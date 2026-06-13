#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxn = 1e5 + 10;
int n;
int a[maxn];

// 查找到第一个大于 target 的元素下标
int findj(int target) 
{
    int l = 1, r = n + 1; 
    while(l < r) 
    {
        int mid = (l + r) / 2;
        if(a[mid] > target) {
            r = mid;
        } else if(a[mid] <= target) {
            l = mid + 1;
        }
    }
    return l;
}

void Sol() {
    int ans = INT_MAX;
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for(int i=1, j; i<=n-1; ++i) {
        // a[i], a[i+1]，默认有第三个数，第三个较大者
        int sum = 0;
        int maxVal = a[i] + a[i+1] - 1;
        j = findj(maxVal);
        // for(j=i+1; j<=n; ++j) {
        //     if(a[j] > maxVal) {
        //         break;
        //     }
        // }
        if(j != n+1) sum += (n-j+1); // 特判，当查找的 j 已经越界（ j > n）
        sum += i-1; // 把前 i-1 个元素改成 maxVal
        if(sum < ans) {
            // printf("i=%d update\n", i);
            ans = min(ans, sum);
        }
    }
    cout << ans << endl;
}
int main() 
{
    int T; cin >> T;
    while(T--) {
        Sol();
    }
    return 0;
}