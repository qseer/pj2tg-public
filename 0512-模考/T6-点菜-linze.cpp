#include<bits/stdc++.h>
const int N=110;
using namespace std;
int a[N],dp[N][10010];
// dp[i][j] 
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    // 1. 初始化
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    // 前 i 个元素，花费 j 元的方案数
    
    dp[__?__][__?__] = __?__
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=a[i]){
                dp[i][j]+=dp[i-1][j-a[i]];
            }
        }
    }
    return 0;
}
