#include<bits/stdc++.h>
using namespace std;
int a[109], b[109];
int dp[50009];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, P, Q;
		cin >> n >> P >> Q;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i];
			// dp[i] = 0;
		}
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			for (int j = Q; j >= b[i]; j--) {
				dp[j] = max(dp[j], dp[j - b[i]] + a[i]);
			}
		}
		int t = 1;
		for (int i = 1; i <= Q; i++) {
			if (dp[i] >= P) {
				cout << i;
				t = 0;
				break;
			}
		}
		if (t == 1)cout << "-1";
		cout << "\n";
	}
	return 0;
}
