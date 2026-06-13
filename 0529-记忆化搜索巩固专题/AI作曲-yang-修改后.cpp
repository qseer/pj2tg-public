#include<bits/stdc++.h>
using namespace std;

// dp[i][j]: 前 i 个音符、且第 i 个音符取值为 j 时的最大得分 (音符下标 0-based, 取值 1..m)
long long dp[106][106], qwq[106][106], a[106];

int main(){
	int t;
	cin >> t;

	while(t--){
		int n, m;
		cin >> n >> m;

		// 修复 BUG①: 矩阵按 1..m 读入, 与固定音符取值 a[i]∈[1,m] 对齐
		for(long long i = 1; i <= m; i++){
			for(long long j = 1; j <= m; j++){
				cin >> qwq[i][j];
			}
		}

		// 音符下标用 0..n-1 (与"取值"是两个独立维度, 这一维原本就没问题)
		for(long long i = 0; i < n; i++){
			cin >> a[i];
		}

		memset(dp, 0, sizeof(dp));
		// 第 0 个音符: 自由则各取值得分均为 0(memset 已置好);
		//   固定则后续只会读取 dp[0][a[0]](=0) 这一个合法状态, 其余不会被读到

		for(long long i = 1; i < n; i++){
			if(a[i] > 0 && a[i - 1] > 0){
				// 当前、前驱都固定: 只有唯一一条转移
				dp[i][a[i]] = dp[i - 1][a[i - 1]] + qwq[a[i - 1]][a[i]];
			}
			else if(a[i] > 0 && a[i - 1] < 0){
				// 当前固定为 a[i], 前驱自由: 枚举前驱取值 k ∈ 1..m
				for(long long k = 1; k <= m; k++){
					dp[i][a[i]] = max(dp[i][a[i]], dp[i - 1][k] + qwq[k][a[i]]);
				}
			}
			else if(a[i] < 0 && a[i - 1] < 0){
				// 当前、前驱都自由: 枚举当前取值 j、前驱取值 k, 均 ∈ 1..m
				for(long long j = 1; j <= m; j++){
					for(long long k = 1; k <= m; k++){
						dp[i][j] = max(dp[i][j], dp[i - 1][k] + qwq[k][j]);
					}
				}
			}
			else if(a[i] < 0 && a[i - 1] > 0){
				// 当前自由, 前驱固定为 a[i-1]: 枚举当前取值 j ∈ 1..m
				for(long long j = 1; j <= m; j++){
					dp[i][j] = max(dp[i][j], dp[i - 1][a[i - 1]] + qwq[a[i - 1]][j]);
				}
			}
		}

		long long ans = 0;
		// 修复 BUG①: 答案在所有取值 1..m 上取最大
		for(long long i = 1; i <= m; i++){
			ans = max(ans, dp[n - 1][i]);
		}

		cout << ans << endl;
	}
	return 0;
}
