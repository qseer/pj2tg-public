#include <bits/stdc++.h>
using namespace std;
int s[111][111], a[111];
int n, m;

// dfs(1, 2): 求解 1 ～ n 的音符最大得分，其中 a[1] = 2
int dfs(int x, int y) {
	if (x == n) {
		return 0;
	}
	// dfs(1, 2), 已知 a[1] = 2，接下来只需枚举 a[2], 就可以算得 score(a[1], a[2])
	if (a[x+1] > 0) {
		int ans = s[ a[x] ][ a[x+1] ] + dfs(x+1, a[x+1]);
		return ans;
	} else { 
		// 枚举 a[x+1] 的值，从 1 ～ m
		int ans = 0;
		for(int i=1; i<=m; ++i) 
		{
			a[x+1] = i;
			ans = max(ans, dfs(x+1, a[x+1]) + s[ a[x] ][ a[x+1] ]);
			a[x+1] = -1;
		}
		return ans;
	}
}
int main() {
	int nn;
	cin >> nn;
	while (nn--) {
		cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> s[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		if(a[1] > 0) cout << dfs(1, a[1]) << endl;
		else if(a[1] == -1)
		{
			int ans = 0;
			for(int i=1; i<=m; ++i) 
			{
				a[1] = i;
				ans = max(ans, dfs(1, i));
			}
			cout << ans << endl;
		}
	}
	return 0;
}