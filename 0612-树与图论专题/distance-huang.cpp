#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> g[1000005];
int root, maxn = INT_MIN, A, B;
int ans[1007891];
void dfs(int u, int fa, int dep = 0) {
	if (dep > maxn) {
		maxn = dep;
		root = u;
	}
	for (auto v : g[u]) {
		if (v != fa) dfs(v, u, dep+1);
	}
}
void dfs2(int node, int fa, int dep = 0) {
	ans[node] = max(dep, ans[node]);
	for (auto v : g[node]) {
		if (v != fa) dfs2(v, node, dep+1);
	}
}
int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 0);
	A = root;
	dfs(root, 0);
	B = root;
	//
	dfs2(A, 0);
	dfs2(B, 0);
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	return 0;
}