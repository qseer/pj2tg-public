#include <bits/stdc++.h>
using namespace std;
int main() {
	int nn;
	cin >> nn;
	while (nn--) {
		long long x, y, k, c;
		cin >> x >> y >> k;
		// 每走 x 步，纵坐标 + 1
		// 总共走完了 T 个周期
		long long T = k / x;
		long long zong = 1 + T;
		long long heng = -1;
		// T 为奇数
		if(T % 2 == 1) 
		{
			heng = x - k % x;
		}

		// T 为偶数
		if(T % 2 == 0) 
		{
			heng = 1 + k % x;
		}
		cout << heng-1 + zong-1 << endl;
	}
	return 0;
}