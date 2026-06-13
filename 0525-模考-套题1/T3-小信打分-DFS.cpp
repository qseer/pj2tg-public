#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
int n, m; // n 表示抽取的次数 
int res[1010];
ll sum, ans;

void Sol() {
    if(sum % n != 0) return ;
    ll ave = sum / n;
    for(int i=1; i<=n; ++i) {
        if(res[i] == ave) {
            ans ++;
        }
        // cout << res[i] << " ";
    }
    // cout << endl;
}

void f(int x) 
{
    if(x == n+1) {
        Sol();
        return ;
    }
    for(int i=0; i<=m; ++i) {
        res[x] = i;
        sum += res[x];
        f(x + 1);
        sum -= res[x];
    }
}

int main() 
{
    cin >> n >> m;
    f(1);
    cout << ans;
    return 0;
}