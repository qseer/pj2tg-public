#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
bool a[N];
int sb[N][3];
int n;
// i 当前怪兽
// turn 0小信，1小友
int dfs(int i,int turn){
    // 剪枝
    if(sb[i][turn]!=-1) return sb[i][turn];
    if(i>n) return 0;// 没有怪了
    if(turn==0){   // 小信回合
        // 小信打一只怪兽受到伤害，然后轮到小友
        int ans=a[i]+dfs(i+1,1);
        // 小信打两只怪兽受到伤害，然后轮到小友
        if(i+1<=n) ans=min(ans,a[i]+a[i+1]+dfs(i+2,1));
        // return ans;
        sb[i][turn]=ans;
    }
    else{    // 小友回合
        // 小友打一个怪，然后轮到小信
        int ans=dfs(i+1,0);  // 小友无敌，没逝
        // 小友打两个怪，然后轮到小信
        if(i+1<=n) ans=min(ans, dfs(i+2,0));
        // return ans;
        sb[i][turn]=ans;
    }
    return sb[i][turn];
}
int main(){
    memset(sb,-1,sizeof sb);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cout<<dfs(1,0);  // 第一个怪，小新先手
    return 0;
}