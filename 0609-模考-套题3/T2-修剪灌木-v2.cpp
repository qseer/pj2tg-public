#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxn = 2e5 + 10;
int n, k, maxh = -1, ans = INT_MAX;
int a[maxn];
int opCnt[maxn]; // opCnt[h] 砍到 h 的高度，最少的砍的次数
int nums[maxn];  // nums[h] 已经砍到 h 高度的灌木数量
// 边界条件，nums[h] == k, 数量够了，就不用继续砍了，opCnt[h] 不用再继续累加 thisCut

// int check(int th) 
// {
//     int cutCnt = 0, thCnt = 0;
//     for(int i=1; i<=n; ++i) 
//     {
//         if(thCnt == k) 
//         {
//             return cutCnt;
//         }
//         if(a[i] < th) continue;
//         int h = a[i], thisCut = 0;
//         while(h > th) 
//         {
//             h /= 2;
//             thisCut ++;
//         }
//         if(h == th) 
//         {
//             cutCnt += thisCut;
//             thCnt ++;
//         }
//     }
//     return INT_MAX;
// }

int main() 
{
    cin >> n >> k;
    for(int i=1; i<=n; ++i) 
    {
        cin >> a[i];
        maxh = max(maxh, a[i]);
    }
    sort(a+1, a+1+n);
    for(int i=1; i<=n; ++i) 
    {
        int h = a[i];
        int thisCut = 0;
        while(h >= 1) 
        {
            if(nums[h] < k) 
            {
                nums[h] ++;
                opCnt[h] += thisCut;
            }
            thisCut ++;
            h /= 2;
        }
    }

    for(int h=1; h<=maxh; ++h) 
    {
        if(nums[h] == k) 
        {
            ans = min(ans, opCnt[h]);
        }
    }

    // for(int th=1; th<=maxh; ++th) // target_height
    // {
    //     ans = min(ans, check(th));
    // }
    cout << ans;
    return 0;
}