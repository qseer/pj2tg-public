#include<bits/stdc++.h>
using namespace std;
long long a[10009], b[10009];
int isp(int h) {
	if (h < 2) return 0;
	if (h == 2) return 1;
	if (h % 2 == 0) return 0;
	for (int i = 3; i * i <= h; i += 2) {
		if (h % i == 0) return 0;
	}
	return 1;
}

int main() {
	int n;
	cin >> n;
	int cnt = 0;
	int ii = 0;
	for (int i = 2; cnt < n; i++) {
		if (isp(i)) {
			a[++cnt] = i;
		}
		ii = i;
	}
	printf("ii=%d\n", ii);
	b[1] = a[n];
	for (int i = 2; i <= n; i++) {
		b[i] = b[i - 1] + a[n - i + 1];
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += b[i];
	}
	cout << ans;
	return 0;
}
