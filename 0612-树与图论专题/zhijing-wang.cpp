#include<bits/stdc++.h>
#if defined(__has_include) && __has_include(<icecream.hpp>)
    #include<icecream.hpp>
#else
    #define IC(...) 1
#endif
#define REP(i,x,y) for(long long i=x;i<=y;i++)
#define R_REP(i,x,y) for(long long i=x;i>=y;i--)
using namespace std;
const int N=1e5+10;
vector<int>v[N];
int n,ans;
int dfs(int now,int fa){
    int maxx=0;
    for(auto it:v[now]){
        if(it==fa)continue;
        int nowlen=dfs(it,now)+1;
        ans=max(ans,nowlen+maxx);
        maxx=max(maxx,nowlen);
    }
    return maxx;
}
int main(){
    cin>>n;
    REP(i,1,n-1){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,-1);
    cout<<ans;
    return 0;
}