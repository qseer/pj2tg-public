#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
ll n, m, k;

void Sol() {
    cin >> n >> m >> k;
    ll T = k / n / 2;
    ll x = 1, y = 1;
    y += 2 * T;
    k = k % (2 * n);
    if(k <= n) {
        cout << x + y + k - 2;
    }
    else {
        x = n - (k - n);
        y ++;
        cout << x + y - 2;
    }
    cout << endl;
}
int main() 
{
    int T; cin >> T;
    while(T--) {
        Sol();
    }
    return 0;
}