#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, a, k = 0;
	cin >> n;
	a = n;
	for (int i = 2; i * i <= n; i++) {
		if (a % i == 0) {
			int s = 0;
			while (a % i == 0) {
				a /= i;
				s++;
			}
			if (k) {
				cout << "* ";
			}
			if (s != 1) {
				cout << i << "^" << s << " ", k = 1;
			} else cout << i << " ", k = 1;
		}
	}
	if (a != 1) {
		if (a != n) {
			cout << "* " << a;
		} else {
			cout << a;
		}
	}
	return 0;
}