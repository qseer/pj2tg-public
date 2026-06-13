#include <bits/stdc++.h>
using namespace std;
int n, p[1000009], t[1000009], c = 0;
void sf() {
	p[1] = 1;
	for (int i = 2; i <= 1000009; i++) {
		if (!p[i]) {
			c++;
			t[c] = i;
			for (int j = i; j <= n / i; j++) {
				p[i * j] = 1;
			}
		}
	}
}
int main() {
//	freopen("B.in", "r", stdin);
//	freopen("B.out", "w", stdout);
	int nn;
	cin >> nn;
	sf();
	while (nn--) {
		int ans = 0;
		cin >> n;
		for (int a = 1; a <= n; a++) {
			for (int i = 1; i <= c; i++) {
				if (a * t[i] > n) {
					break;
				}
				ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
