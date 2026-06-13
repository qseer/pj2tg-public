#include<bits/stdc++.h>
using namespace std;
int del[100009];
struct g {
	int a, b;
} a[100009];
int main() {
	int n;
	cin >> n;
	a[0].b = 1;
	a[1].a = 0;
	a[1].b = 0;
	for (int i = 2; i <= n; i++) {
		int k, p;
		cin >> k >> p;
		if (p == 0) {
			a[i].a = a[k].a;
			a[i].b = k;
			a[a[k].a].b = i;
			a[k].a = i;
		} else {
			a[i].a = k;
			a[i].b = a[k].b;
			a[a[k].b].a = i;
			a[k].b = i;
		}
	}
	int m;
	cin >> m;
	while (m--) {
		int x;
		cin >> x;
		del[x] = 1;
		// 删除操作，需要更新链子
	}
	int i = 1, now = a[0].b;
	while (now != 0) {
		if (!del[now]) {
			cout << now << " ";
			// if (!i) cout << " ";
			// i = 0;
		}
		now = a[now].b;
	}
	return 0;
}
