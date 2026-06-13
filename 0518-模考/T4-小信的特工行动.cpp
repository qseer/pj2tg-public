#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using PII = pair<int, int>;
unordered_map<ull, string> f;
int n; 
string str;
bool flag;
ull s, b[50];
ull ULL_MAX = 0xffffffffffffffff;

void dfs1(int x, ull sum) {
    if(x > n/2) {
        f[sum] = str.substr(1, n/2);
        return ;
    }
    // 1. 选 
    str[x] = '1';
    dfs1(x + 1, sum + b[x]);
    // 2. 不选 
    str[x] = '0';
    dfs1(x + 1, sum);
}

void dfs2(int x, ull sum) {
    if(flag) return ;
    if(x > n) {
        ull left;
        left = s - sum;
        if(f.count(left)) {
            string temp = str.substr(n/2+1, n - n/2);
            cout << f[left];
            cout << temp;
            flag = true;
        }
        return ;
    }
    // 1. 选 
    str[x] = '1';
    dfs2(x + 1, sum + b[x]);
    // 2. 不选 
    str[x] = '0';
    dfs2(x + 1, sum);
}

int main() 
{
    str.resize(100);
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> b[i];
    cin >> s;
    dfs1(1, 0);
    dfs2(n/2+1, 0);
    return 0;
}