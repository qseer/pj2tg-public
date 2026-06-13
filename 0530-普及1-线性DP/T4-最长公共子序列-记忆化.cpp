#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n, m, memo[maxn][maxn];
string s, t;

// dfs(i,j) = s 前 i 个字符与 t 前 j 个字符的 LCS 长度
int dfs(int i, int j)
{
    if(i == 0 || j == 0) return 0;
    if(memo[i][j] != -1) return memo[i][j];
    if(s[i-1] == t[j-1]) return memo[i][j] = dfs(i-1, j-1) + 1;
    return memo[i][j] = max(dfs(i-1, j), dfs(i, j-1));
}

int main()
{
    cin >> s >> t;
    n = s.size(); m = t.size();
    memset(memo, -1, sizeof(memo));
    cout << dfs(n, m);
    return 0;
}
