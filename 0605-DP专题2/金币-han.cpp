#include <bits/stdc++.h>
using namespace std;
int s[111], t[111], tt[111], n;
int ans = 0;

void dfs(int q, int w, int a) {
	ans = max(ans, a);
	for (int i = 1; i <= n; i++) {
		if (!tt[i] && s[i] >= w && t[i] >= q && t[i] - q >= s[i] - w) {
			tt[i] = 1;
			dfs(t[i], s[i], a + 1);
			tt[i] = 0;
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i] >> t[i];
	}
	dfs(0, 0, 0);
	cout << ans;
	return 0;
}