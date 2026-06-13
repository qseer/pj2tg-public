#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int s[maxn], t[maxn];
int main() {
	int nn;
	cin >> nn;
	while (nn--) {
		memset(t, 0, sizeof(t));
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> s[i];
		}
		for (int ii = 1; ii <= n; ii++) { // ii 变量枚举 s[1] ~ s[n]
			for (int i = 2; i * i <= s[ii]; i++) { // i 变量枚举质因数
				if (s[ii] % i == 0) {
					while (s[ii] % i == 0) {
						t[i]++; // 究竟是统计谁的个数？
						s[ii] /= i;
					}
				}
			}
			if (s[ii] > 1) {
				t[s[ii]]++;
			}
		}
		int f = 1;
		for (int i = 2; i <= 1e6; i++) {
			// if(t[i] != 0) {
			// 	printf("t[%d]=%d\n", i, t[i]);
			// }
			if (t[i] != 0 && t[i] % n != 0) {
				f = 0;
				cout << "NO";
				break;
			}
		}
		if (f)cout << "YES";
		cout << endl;
	}
	return 0;
}