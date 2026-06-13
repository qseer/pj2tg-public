#include <bits/stdc++.h>
using namespace std;
const int maxm = 1e6 + 10;
int n, k, cnt;
long long tong[maxm];
int aa[5050], d[5050], res[5050];
bool vis[5050];
long long ans = 1e18;
struct Node { int date, id; } a[5050];

bool cmp(const Node &x, const Node &y)
{
    return x.date < y.date;
}

long long getPunish()
{
    long long sum = 0;
    // d[1]~d[k]
    for (int i = 1, j = 1; j <= n; j++)
    {
        while (d[i] < a[j].date && i <= k)
        {
            i++;
        }
        if (d[i] >= a[j].date)
        {
            sum += (d[i] - a[j].date) * (d[i] - a[j].date);
        }
    }
    return sum;
}
void update()
{
    for (int i = 1, j = 1; j <= n; j++)
    {
        while (d[i] < a[j].date && i <= k)
        {
            i++;
        }
        if (d[i] >= a[j].date)
        {
            res[a[j].id] = d[i];
        }
    }
}
void dfs(int x, int last)
{
    if (x >= k)
    {
        // 统计答案
        long long val = getPunish();
        if (val < ans)
        {
            ans = val;
            update();
        }
        return;
    }
    for (int i = last + 1 /*从上一个日期的id结尾开始*/; i < cnt; i++)
    {
        if (vis[i] == false)
        {
            d[x] = aa[i];
            vis[i] = true;
            dfs(x + 1, i);
            vis[i] = false;
        }
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].date;
        tong[a[i].date]++;
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 0; i <= 1e6; i++)
    {
        if (tong[i])
        {
            aa[++cnt] = i;
        }
    }
    d[k] = aa[cnt];
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}