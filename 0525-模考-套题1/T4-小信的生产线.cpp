#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxn = 2e5 + 10;

struct Seg {
    int l, r;
}segs[maxn];

struct Arm {
    int x, y;
}arms[maxn];

bool cmp(const Arm &a, const Arm &b) {
    return a.x < b.x;
}

void merge(int y1, int y2) {
    Seg temp = {min(segs[y1].l, segs[y2].l), max(segs[y1].r, segs[y2].r)};
    segs[y1] = temp;
    segs[y2] = temp;
}

int main() 
{
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=m; ++i) {
        cin >> arms[i].x >> arms[i].y;
    }
    sort(arms + 1, arms + 1 + m, cmp);
    for(int i=1; i<=n; ++i) {
        segs[i] = {i, i};
    }
    for(int i=1; i<=m; ++i) {
        merge(arms[i].y, arms[i].y + 1);
    }
    for(int i=1; i<=n; ++i) {
        cout << segs[i].r - segs[i].l + 1 << " ";
    }
    return 0;
}