#include <bits/stdc++.h>
using namespace std;
int s[111][111], a[111], ans = 0;
int n, m;

// 状态是：对当前子问题的描述，状态是对当前子问题的编码
// [3, 6]: 前 3 个草药，容量为 6 的时候，的最大价值

// dfs(1, 2): 给 a[2] 决策，开头的音符是 2 号音符, 得到 score(2, a[2]) + dfs(2, a[2])
// dfs(2, a[2]) 表示的子问题：对 2 ～ n 的音符决策后，并且开头的音符为 a[2] 时，的最大得分
// dfs(5, 3): 确定好了 a[1] ~ a[5] 的音符，还剩下 a[6] ~ a[n] 等待决策，a[6] ~ a[n] 决策后可以得到的最大得分
int dfs(int x, int y) {
	if (x > n) {
		__?__
		return;
	}
	if (a[x+1] < 0) {
		// 枚举是 a[x+1]
		int temp = 0;
		for (int i = 1; i <= m; i++) {
			a[x+1] = i;
			temp = max(temp, s[a[x]][a[x+1]] + dfs(x+1, a[x+1]));
			a[x+1] = -1;
		}
		dp[x][y] = temp;
	} else { 
		// a[x+1] > 0
		return s[y][a[x+1]] + dfs(x+1, a[x+1]);
	}
}
int main() {
	int nn;
	cin >> nn;
	while (nn--) {
		ans = 0;
		cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> s[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		dfs(1, 0);
		cout << ans << '\n';
	}
	return 0;
}