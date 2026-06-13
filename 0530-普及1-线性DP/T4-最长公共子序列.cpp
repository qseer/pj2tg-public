#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n, m, dp[maxn][maxn];
string s, t;

int main()
{
    cin >> s >> t;
    n = s.size(); m = t.size();
    // dp[i][j] = s 前 i 个字符与 t 前 j 个字符的 LCS 长度
    // s[i-1]==t[j-1] 时一定可以把它们配对：dp[i-1][j-1]+1
    // 否则丢掉 s[i-1] 或 t[j-1] 之一，取较大者
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else                 dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    cout << dp[n][m];
    return 0;
}
