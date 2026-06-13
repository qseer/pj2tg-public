#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxn = 1010;
struct Node {
    ll t, x, y;
}a[maxn];

double getDis(Node u, Node v) {
    double temp = 1.0 * (v.x - u.x) * (v.x - u.x) + (v.y - u.y) * (v.y - u.y);
    return sqrt(temp);
}

void Sol() {
    double ans = 0;
    int n; cin >> n;
    for(int i=1; i<=n; ++i) {
        cin >> a[i].t >> a[i].x >> a[i].y;
    }
    for(int i=2; i<=n; ++i) {
        double dis = getDis(a[i-1], a[i]);
        double dif = dis / (a[i].t - a[i-1].t);
        ans = max(ans, dif);
    }
    printf("%.10lf\n", ans);
}

int main() 
{
    int T; cin >> T;
    while(T--) {
        Sol();
    }
    return 0;
}