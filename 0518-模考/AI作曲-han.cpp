#include <bits/stdc++.h>
using namespace std;
int s[111][111], a[111], ans = 0;
int n, m;
void dfs(int x, int ii) {
	if (x > n) {
		if (ii > ans) ans = ii;
		return 0;
	}
	if (a[x] < 0) {
		for (int i = 1; i <= m; i++) {
			int t = a[x];
			a[x] = i;
			dfs(x + 1, ii + s[a[x - 1]][a[x]]);
			a[x] = t;
		}
	} else {
		dfs(x + 1, ii + s[a[x - 1]][a[x]]);
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