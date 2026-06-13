#include <iostream>
#include <vector>
#include <climits>
using namespace std;
const int maxm = 400 * 1000 * 3;
const int ZERO = 400 * 1000;

int main() 
{
    vector<int> dp(maxm, INT_MIN);
    // 设定零点 400,000
    dp[ZERO] = 0;

    int n; cin >> n;
    for(int i=1; i<=n; ++i) {
        int s, f;
        cin >> s >> f;
        if(s >= 0) {
            for(int j=ZERO*2; j>=s; --j) {
                if(dp[j-s] != INT_MIN)
                dp[j] = max(dp[j], dp[j - s] + f);
            }
        }
        else if(s < 0) {
            for(int j=0; j<=ZERO*2+s; ++j) {
                if(dp[j-s] != INT_MIN)
                dp[j] = max(dp[j], dp[j - s] + f);
            }
        }
    }
    int ans = 0;
    for(int j=ZERO; j<=ZERO*2; ++j) {
        if(dp[j] >= 0) {
            ans = max(ans, j + dp[j] - ZERO);
        }
    }
    cout << ans;
    return 0;
}