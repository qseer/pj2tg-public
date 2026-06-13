#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int num=s[1]-'0';
        a.push_back(num);
    }
    // res[i] LIS 第 i 位的最小值
    vector<int>res;
    for(int i=0;i<a.size();i++){
        int x=a[i];
        int l=0,r=res.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(res[mid]>=x){
                r=mid-1;
            }
            else{ // res[mid] < x
                l=mid+1;
            }
        }
        if(l==res.size()){ // l 落在第一个 >= x 的位置
            res.push_back(x);
        }
        else{
            res[l]=x;
        }
    }
    cout<<n-res.size()<<endl;
    return 0;
}