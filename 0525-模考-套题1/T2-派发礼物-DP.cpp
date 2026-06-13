#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxn = 5010;
struct Gift {
    int date, id;
}gifts[maxn];
ll sum[maxn][maxn];
int ans[maxn];
vector<vector<ll>> dp(maxn, vector<ll>(25, (ll)1e18));
int n, K; 

bool cmp(const Gift& a, const Gift& b) {
    return a.date < b.date;
}

void init() {
    for(int i=1; i<=n; ++i) {
        for(int j=i-1; j>=1; --j) {
            sum[j][i] = sum[j+1][i] + (gifts[i].date - gifts[j].date) * (gifts[i].date - gifts[j].date);
        }
    }
}

void update(int l, int r) {
    int date = gifts[r].date;
    for(int i=l; i<=r; ++i) {
        int id = gifts[i].id;
        ans[id] = date;
    }
}

int main() 
{
    cin >> n >> K;
    for(int i=1; i<=n; ++i) {
        cin >> gifts[i].date;
        gifts[i].id = i;
    }
    sort(gifts + 1, gifts + 1 + n, cmp);
    init();
    dp[0][0] = 0;
    for(int i=1; i<=n; ++i) {
        for(int j=0; j<i; ++j) {
            for(int k=1; k<=K; ++k) {
                dp[i][k] = min(dp[i][k], dp[j][k-1] + sum[j+1][i]);
            }
        }
    }
    // cout << "dp 完成";
    int lst = n;
    for(int k=K; k>=1; --k) {
        for(int i=0; i<lst; ++i) {
            if(dp[lst][k] == dp[i][k-1] + sum[i+1][lst]) {
                update(i+1, lst);
                lst = i;
                break;
            }
        }
    }
    for(int i=1; i<=n; ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}