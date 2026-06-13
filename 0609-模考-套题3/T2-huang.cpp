#include <bits/stdc++.h>
using namespace std;
int n, k, ans = INT_MAX;
int a[200005];
int main() {
	cin >> n >> k;
	memset(a, 0, sizeof a);
	for (int i = 1; i <= n; i++) cin >> a[i];

	// 预处理每个灌木的切的信息，记下来。记什么？

	for (int tar = 0; tar <= 1000000; tar++) {
		int ops[78], cnt = 0;
		// 后续需要查询 tar 高度，最少切的次数，直接拿来用记下来的信息
		// 切到高度为 tar 的最少次数


		// 每个灌木只处理一次，10 -> 5 -> 2 -> 1


		// for (int i = 1; i <= n; i++) {
		// 	int h = a[i], stp = 0;
		// 	while (h > tar) { 
		// 		h = h / 2;
		// 		stp++;
		// 	}
		// 	if (h == tar) { 
		// 		ops[++cnt] = stp;
		// 	}
		// }
		if (cnt >= k) {
			sort(ops+1, ops+n+1);
			int sum = 0;
			for (int i = 1; i <= k; i++) sum += ops[i];
			if (sum < ans) ans = sum;
		}
	}
	cout << ans << '\n';
	return 0;
}