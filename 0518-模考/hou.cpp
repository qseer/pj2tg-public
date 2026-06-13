#include <bits/stdc++.h>
using namespace std;
int score[60][60];
int a[110];
int n,m,maxx=INT_MIN;
void dfs(int x){
    if(x>n){
        int ans=0;
        for(int i=1;i<n;i++){
            ans+=score[a[i]][a[i+1]];
        }
        maxx=max(maxx,ans);
        return;
    }
    if(a[x]<0){
        for(int i=1;i<=m;i++){
            a[x]=i;
            dfs(x + 1);
            a[x]=-1;
        }
    }
    else{
        dfs(x+1);
    }
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) cin>>score[i][j];
        for(int i=1;i<=n;i++) cin>>a[i];
        dfs(1);
        cout<<maxx<<endl;
        maxx=INT_MIN;
    }
    return 0;
}