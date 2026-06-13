#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxn = 1e5 + 10;
const int maxm = 1e7;
int n, ans;
int a[maxn], prefix[maxn];
// map<int, bool> flag;
bool vis[maxm];

bool check(int target) {
    int l = 1, r = n;
    while(l <= r) 
    {
        int mid = (l + r) / 2;
        if(prefix[mid] < target) {
            l = mid + 1;
        } 
        else if(prefix[mid] > target) {
            r = mid - 1;
        }
        else if(prefix[mid] == target) {
            return true;
        }
    }
    return false;
}

int main() 
{
    cin >> n;
    for(int i=1; i<=n; ++i) {
        cin >> a[i];
        prefix[i] = prefix[i-1] + a[i];
        // flag[prefix[i]] = true;
        vis[prefix[i]] = true;
        // 第 i 个点，在坐标轴上的坐标 prefix[i]
    }
    int L = prefix[n];
    if(L % 3 != 0) {
        cout << 0;
        return 0;
    }
    int part = L / 3;
    for(int i=1; i<=n; ++i) {
        int L2 = prefix[i] + part;
        int L3 = prefix[i] + part + part;
        // 怎么查找 L2 的位置存在一个点？
        // 怎么查找 L3 的位置存在一个点？
        if(check(L2) && check(L3)) {
        // if(vis[L2] && vis[L3]) {
            ans ++;
        }
    }
    cout << ans;
    return 0;
}