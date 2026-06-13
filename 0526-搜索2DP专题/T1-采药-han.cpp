#include <bits/stdc++.h>
using namespace std;
int a[1009], b[1009];

// dfs(3, 8) 描述的子问题，剩 3 株草药需要决策，剩 8 的背包容量，能够获得的最大价值 => dfs(3, 8) 的返回值 => dp[3][8] 存下来
int dfs(int x, int ii) {
	// printf("dfs(%d, %d)\n", x, ii);
	int yes = 0, no = 0;
	if (x == 0) {
		return 0;
	}
	if (ii >= a[x]) {
		yes = dfs(x - 1, ii - a[x]) + b[x];
	}
	no = dfs(x - 1, ii);
	return max(yes, no);
}

int main() {
	int n, k;
	cin >> k >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	cout << dfs(n, k);
	return 0;
}