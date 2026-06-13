#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxn = 2e5 + 10;
int n, k, maxh = -1, ans = INT_MAX;
int a[maxn];
int cnt[maxn]; // cnt[h] 砍到 h 的高度，最少的砍的次数
int num[maxn]; // num[h] 已经砍到 h 高度的灌木数量
// 边界条件，nums[h] == k, 数量够了，就不用继续砍了，cnt[h] 不用再继续累加 thisCut
int main() 
{
    cin >> n >> k;
    for(int i=1; i<=n; ++i) 
    {
        cin >> a[i];
        maxh = max(maxh, a[i]);
    }
    sort(a+1, a+1+n);
    for(int i=1; i<=n; ++i) // 预处理每颗灌木，从矮到高按顺序依次处理。将每次「砍后的信息」存储在 cnt[] 和 num[] 中
    {
        int h = a[i];
        int thisCut = 0;
        while(h >= 1) 
        {
            if(num[h] < k) // h 不够 k 个，继续维护 cnt[h] 和 num[h] 两个数组的信息；若已经足够 k 个，则不再维护。
            {
                num[h] ++;
                cnt[h] += thisCut;
            }
            thisCut ++;
            h /= 2;
        }
    }
    for(int h=1; h<=maxh; ++h) // 枚举所有可能的高度 h，对「足够 k 个」的灌木高度 h，所砍的最少次数 cnt[h] 打擂台
    {
        if(num[h] == k) 
        {
            ans = min(ans, cnt[h]);
        }
    }
    cout << ans;
    return 0;
}