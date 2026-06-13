#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n, ans=INT_MAX, temp[maxn], dp[maxn];
int p[10], vis[10];
map<char, int> ty;
struct Card {
    char col;
    int val;
}cards[maxn];
int colVal[10];
// int colVal[] = {0, n, 2*n, 3*n, 4*n};

int LIS() 
{
    int res = 0;
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=n; ++i) {
        dp[i] = 1;
        for(int j=1; j<i; ++j) {
            if(temp[i] > temp[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
        res = max(res, dp[i]);
    }
    return res; 
}

int check() 
{
    for(int i=1; i<=n; ++i) {
        if(cards[i].col == 'X') {
            temp[i] = 4 * n + cards[i].val;
        }
        else {
            int t = ty[cards[i].col]; // 花色 Id
            // 第 t 种花色上的权值
            temp[i] = colVal[t] + cards[i].val;
        }
    }
    return n - LIS();
}

void dfs(int x) 
{
    if(x >= 4) 
    {
        ans = min(ans, check());
        return ;
    }
    for(int i=0; i<4; ++i) 
    {
        if(vis[i] == false) {
            colVal[x] = i * n;
            vis[i] = true;
            dfs(x + 1);
            vis[i] = false;
        }
    }
}

int main() 
{
    ty['C'] = 0; ty['A'] = 1;
    ty['M'] = 2; ty['P'] = 3;
    // ty['X'] = 4
    cin >> n;
    for(int i=1; i<=n; ++i) {
        string str;
        cin >> str;
        cards[i].col = str[0];
        cards[i].val = stoi(str.substr(1));
    }
    dfs(0);
    cout << ans;
    return 0;
}