#include<bits/stdc++.h>
using namespace std;
int n,c,res=1;
int a[101][101];
int dp[101][101];
const int mx[4]={0,1,0,-1};
const int my[4]={1,0,-1,0};
bool check(int x,int y){
	if(x>=0&&x<n&&y>=0&&y<c)return true;
	return false;
}
// dfs(x, y) 的子问题定义：从 (x, y) 出发可以走的最多步数。
// 根据子问题的定义，可以推出递归公式 dfs(x, y) = max { dfs(nx, ny) + 1 } (nx, ny) 表示所有可能的下一个位置坐标
int dfs(int x,int y){
	// 记忆化的剪枝
	if(dp[x][y] != -1) return dp[x][y];

	// 递归的终止条件/边界条件，表示走到了最小的子问题，答案已经显而易见
	// if(没路可走) 
	// {
	// 	return 0;
	// }
	int ans = 0;
	for(int i=0;i<4;i++){
		int dx=x+mx[i],dy=y+my[i];
		if(check(dx,dy)&&a[dx][dy]<a[x][y]){
			ans = max(ans, dfs(dx,dy) + 1);
		}
	}
	// ans=max(ans,s);
	dp[x][y] = ans;
	return ans;
}
int main() {
	memset(dp, -1, sizeof(dp));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>c;
	for(int i=0;i<n;i++){
		for(int j=0;j<c;j++)cin>>a[i][j];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<c;j++) res = max(res, dfs(i,j));
	}
	cout<<res+1;
	return 0;
}