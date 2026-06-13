#include <bits/stdc++.h>
using namespace std;
int a[1000009];
int dp[1000009][2];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i <= n; ++i) {
		dp[i][0] = dp[i][1] = 1e9;
	}
	dp[0][1] = 0;
	for (int i = 0; i <= n; ++i) {
		if (dp[i][1] != 1e9) {
			if (i + 1 <= n)
				dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + a[i + 1]);
			if (i + 2 <= n)
				dp[i + 2][0] = min(dp[i + 2][0], dp[i][1] + a[i + 1] + a[i + 2]);
		}
		if (dp[i][0] != 1e9) {
			if (i + 1 <= n)
				dp[i + 1][1] = min(dp[i + 1][1], dp[i][0]);
			if (i + 2 <= n)
				dp[i + 2][1] = min(dp[i + 2][1], dp[i][0]);
		}
	}
	cout << dp[n][1];
	return 0;
}