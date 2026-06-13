#include<bits/stdc++.h>
using namespace std;
int n,k,d[5010],ans[5010],now[5010],minc=INT_MAX;
void check(){
    int day[5010]={0};
    int sum=0;
    for(int i=0;i<n;i++){
        day[now[i]]=max(day[now[i]],d[i]);
    }
    for(int i=0;i<n;i++){
        sum+=(day[now[i]]-d[i])*(day[now[i]]-d[i]);
    }
    if(sum>=minc)return;
    minc=sum;
    for(int i=0;i<n;i++){
        ans[i]=day[now[i]];
    }
}
void dfs(int u){
    if(u==n){
        check();
        return;
    }
    for(int x=1;x<=k;x++){
        now[u]=x;
        dfs(u+1);
    }
}

总共有 k 个派发日，派发的时候只会在最佳派发日派发

dfs(1)
dfs(2)
...
dfs(k)


int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    dfs(0);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}