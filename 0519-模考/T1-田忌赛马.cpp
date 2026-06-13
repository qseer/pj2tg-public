#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
int v[5], a[5];
int p[5];
bool ans;
bool vis[5];

bool check() 
{
    int cnt = 0;
    for(int i=1; i<=3; ++i) {
        if(a[p[i]] > v[i]) cnt ++;
    }
    return cnt >= 2;
}

void dfs(int x)
{
    if(x > 3) {
        ans = ans || check();
        return ;
    }
    for(int i=1; i<=3; ++i) {
        if(vis[i] == false) {
            p[x] = i;
            vis[i] = true;
            dfs(x + 1);
            vis[i] = false;
        }
    }
}

int main() 
{
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    for(int i=1; i<=3; ++i) cin >> v[i];
    for(int i=1; i<=3; ++i) cin >> a[i];
    dfs(1);
    cout << (ans? "Yes": "No");
    return 0;
}