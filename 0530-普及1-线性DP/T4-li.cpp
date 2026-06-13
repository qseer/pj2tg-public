#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10001;
int dp[MAXN][MAXN][MAXN] = {0};
int dfs(int a, int b, int c) {
	if (dp[a][b][c] != -1) {
		return dp[a][b][c];
	}
	if (a <= 0 || b <= 0 || c <= 0) {
		dp[a][b][c] = 1;
		return dp[a][b][c];
	}
	if (a > 20 || b > 20 || c > 20) {
		dp[a][b][c] = dfs(20,20,20);
		return dp[a][b][c];
	}
	if (a < b && b < c) {
		dp[a][b][c] = dfs(a,b,c-1) + dfs(a,b-1,c-1) - dfs(a,b-1,c);
		return dp[a][b][c];
	}
	
	dp[a][b][c] = dfs(a-1,b,c) + dfs(a-1,b-1,c) + dfs(a-1,b,c-1) - dfs(a-1,b-1,c-1);
	return dp[a][b][c];
}

int main() {
	memset(dp,-1,sizeof(dp));
	int a,b,c;
	while (true) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) {
			break;
		}
		cout << "w(" << a << ", " << b << ", " << c << ") = " << dfs(a,b,c) << endl;
	}
	return 0;
}
