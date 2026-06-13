#include<bits/stdc++.h>
using namespace std;

long long dp[106][106], qwq[106][106], a[106];

int main(){
	int t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		// ===== BUG①(致命/核心错误): 取值下标 0-based 与 1-based 混用 =====
		// 题意: 音符取值范围是 1..m, 固定音符 a[i] 也落在 1..m
		// 这里却把矩阵存进 qwq[0..m-1][0..m-1] (0-based):
		//   · 固定音符访问 qwq[a[i-1]][a[i]] 时, 下标会取到 m (越过已填范围, 读到 0)
		//   · 本该是第 1 行的数据被存到了下标 0, 整张表整体错位一格
		//   · 下面自由音符又按 0..m-1 枚举, 与固定音符的 1..m 不在同一套编号里
		// 现象: 全是自由音符时(自洽地用 0..m-1)能蒙对; 一旦出现固定音符就算错
		// 正解: 矩阵按 1..m 读入, 后续所有取值枚举/答案统计都用 1..m
		for(long long  i = 0; i < m; i++){
			for(long long j = 0; j < m; j++){
				cin >> qwq[i][j];
			}
		}
		
		for(long long i = 0; i  < n; i++){
			cin >> a[i];
		}
		
		// 说明(非 bug): dp 初值置 0 在本解法里是安全的——
		//   下面用"前驱音符是否固定"分类: 固定前驱只读 dp[i-1][a[i-1]] 这一个合法状态,
		//   自由前驱时所有 k 都合法; 故无需像标程那样用 -1 标记不可达(前提: 得分非负)
		memset(dp, 0, sizeof(dp));
		
		for(long long int i = 1; i < n; i++){
			if(a[i] > 0 && a[i - 1] > 0){
				dp[i][a[i]] = dp[i - 1][a[i -1 ]]+qwq[a[i - 1]][a[i]];
			}
			
			else if(a[i] > 0 && a[i - 1] < 0){
				// BUG①: 枚举前驱取值的范围应为 1..m, 这里 0..m-1 漏掉了取值 m, 还多算了不存在的取值 0
				for(long long k = 0; k < m; k++){
					dp[i][a[i]] = max(dp[i][a[i]], dp[i - 1][k] + qwq[k][a[i]]);
				}
			}
			
			else if(a[i] < 0 && a[i - 1] < 0){
				// BUG①: 当前取值 j 与前驱取值 k 都应枚举 1..m, 这里 0..m-1 错位
				for(long long j = 0; j < m; j++){
					for(long long  k = 0; k < m; k++){
						dp[i][j] = max(dp[i][j], dp[i - 1][k] + qwq[k][j]);
					}
				}
			}
			
			else if(a[i] < 0 && a[i - 1] > 0){
				// BUG①: 当前取值 j 应枚举 1..m, 这里 0..m-1 错位
				for(long long j = 0; j < m; j++){
					dp[i][j] = max(dp[i][j], dp[i - 1][a[i - 1]] + qwq[a[i - 1]][j]);
				}
			}
		}
		
		long long ans = 0;
		
		// BUG①: 统计答案的取值范围也应是 1..m, 这里 0..m-1 漏掉取值 m
		for(long long i = 0; i < m; i++){
			ans = max(ans, dp[n - 1][i]);
		}
		
		cout << ans << endl;
	}
	return 0;
}