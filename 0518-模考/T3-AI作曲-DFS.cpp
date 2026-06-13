#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxm = 55;
const int maxn = 105;
int n, m, sum, ans, maxScore;
int a[maxn];
int score[maxm][maxm];

void output() 
{
    for(int i=1; i<=n; ++i) cout << a[i] << " ";
    printf("sum=%d\n", sum);
    getchar();
}

void dfs(int x) 
{
    if(sum + (n-x+1)*maxScore < ans) return ;
    if(x > n) 
    {
        // output();
        ans = max(ans, sum);
        return ;
    }
    if(a[x] > 0) {
        sum += score[a[x-1]][a[x]];
        dfs(x + 1);
        sum -= score[a[x-1]][a[x]];
    }
    else {
        for(int i=1; i<=m; ++i) 
        {
            a[x] = i;
            sum += score[a[x-1]][a[x]];
            dfs(x + 1);
            sum -= score[a[x-1]][a[x]];
            a[x] = -1;
        }
    }
}

void solve() 
{
    cin >> n >> m;
    for(int i=1; i<=m; ++i) 
    {
        for(int j=1; j<=m; ++j) 
        {
            cin >> score[i][j];
            maxScore = max(maxScore, score[i][j]);
        }
    }
    for(int i=1; i<=n; ++i) cin >> a[i];
    dfs(1);
    cout << ans << endl;
}

int main() 
{
    int T; cin >> T;
    while(T--) 
    {
        ans = -1;
        maxScore = -1;
        solve();
    }
    return 0;
}