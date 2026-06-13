#include <bits/stdc++.h>
using namespace std;
int s[100009], t[11] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, h, n, ans = 0, hh = 0, jj = 0;
void dfs(int x) {
	if (n == 0) {
		ans = 0;
		for (int i = 1; i <= x - 1; i++) {
			ans = ans * 10 + s[i];
		}
		jj = min(jj, ans);
		return;
	}
	if (n < 0) {
		return;
	}
	if (x == 1) {
		for (int i = 1; i <= 9; i++) {
			s[x] = i;
			int uu = n;
			n -= t[i];
			hh = i;
			dfs(x + 1);
			n = uu;
			hh = 0;
			s[x] = 0;
		}
	} else {
		for (int i = 0; i <= 9; i++) {
			s[x] = i;
			int uu = n;
			n -= t[i];
			hh = i;
			dfs(x + 1);
			n = uu;
			hh = 0;
			s[x] = 0;
		}
	}
}
int main() {
	cin >> h;
	while (h--) {
		// ans = INT_MAX;
		jj = INT_MAX;
		hh = 0;
		cin >> n;
		dfs(1);
		if(jj == INT_MAX) cout << -1 << "\n";
		else cout << jj << "\n";
	}
	return 0;
}