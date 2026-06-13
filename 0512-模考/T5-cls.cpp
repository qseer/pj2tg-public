#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1005], ans, N, n, c, sum = 0;
ll houzhui[1005];
void dfs(ll x) {
	// 可行性剪枝
	if(sum > c) return ;
	// 最优性剪枝
	// 已经做到了第 x 件物品的决策，发现 a[x] ~ a[n] 全部选上，还是比 ans 小
	if(sum + houzhui[x] <= ans) return ;

	// 终止条件
	if (x > n) 
	{
		ans = max(ans, sum);
		return;
	}

	// 1. 选第 x 件物品
	sum += a[x];
	dfs(x+1);
	sum -= a[x];
	// 2. 不选第 x 件物品
	dfs(x+1);
}
int main() {
	cin >> N >> c;
	// a[i] >= a[i-1] + a[i-2]
	// a[i] = a[i-1] + a[i-2]
	for (int i = 1; i <= N; i++) { // 合法的 n 不会太大，n < 50
		ll x; cin >> x;
		if(x <= c) a[++n] = x;
	}
	// 优化搜索顺序，先对大砝码做决策，尽可能先搜索到一个较大的 ans，筛除掉小 ans 的方案
	sort(a+1, a+1+n, greater<ll>());
	for(int i=n; i>=1; --i) houzhui[i] = houzhui[i+1] + a[i];
	dfs(1);
	cout << ans;
	return 0;
}