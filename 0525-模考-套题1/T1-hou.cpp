#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int main(){
    int t;
    cin>>t;
    while(t--){
        memset(a,0,sizeof a);
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        int minn=INT_MAX;
        sort(a+1,a+1+n);
        if(n < 3) minn = 0;
        for(int i=1;i<n;i++){
            int ans1=0;
            // 默认了最小值唯一，那么要确保 a[i] 只有一个
            for(int j=1;j<=n;j++){
                if(a[j]>=(a[i]+a[i+1])) ans1++;
                else if(a[i] < a[i+1] && j != i && a[j] < a[i+1]) ans1++;
                else if(a[j]<a[i]) ans1++;
            }
            minn = min(minn, ans1);
        }
        cout<<minn<<endl;
    }
    return 0;
}