#include <bits/stdc++.h>
using namespace std;

const int maxn = 15;

int n;
int a[maxn];
vector<int> subset;  // 当前子集

// 当前考虑第 pos 个元素
void dfs(int pos)
{
    if(pos > n)
    {
        cout << "{";
        for(int i = 0; i < (int)subset.size(); ++i)
        {
            if(i) cout << ", ";
            cout << subset[i];
        }
        cout << "}\n";
        return;
    }
    // 不选 a[pos]
    dfs(pos + 1);
    // 选 a[pos]
    subset.push_back(a[pos]);
    dfs(pos + 1);
    subset.pop_back();  // 回溯
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    dfs(1);
    return 0;
}
