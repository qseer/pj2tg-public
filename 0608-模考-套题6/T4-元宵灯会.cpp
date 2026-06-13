#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
string str;
const int maxn = 5050;
int cnt, rcnt;

struct Node {
    int l, r, flag;
}nodes[maxn];

void build() 
{
    stack<int> stk;
    for(int i=0; i<str.length(); ++i) 
    {
        char c = str[i];
        if(c == '(') {
            ++ cnt;
            if(stk.empty() == false) {
                int fa = stk.top();
                if(nodes[fa].l == 0) nodes[fa].l = cnt;
                else nodes[fa].r = cnt;
            }
            stk.push(cnt);
        } 
        else if(c == 'B') {
            rcnt ++;
            nodes[stk.top()].flag = 1;
        }
        else if(c == ')') {
            if(str[i-1] == '(') nodes[stk.top()].flag = 2;
            stk.pop();
        }
    }
}

void preOrder(int u) 
{
    // if(nodes[u].flag == 1 || nodes[u].flag == 2) return ;
    if(u == 0) return ;
    preOrder(nodes[u].l);
    cout << u << " ";
    preOrder(nodes[u].r);
}

int divide(int u, int r)
{
    if(nodes[u].flag > 0) {
        if(r > 1) return 2000;
        if(nodes[u].flag == 2 && r == 1) return 1;
        // if(nodes[u].flag == 2 && r == 0) return 0;
        // if(nodes[u].flag == 1 && r == 1) return 0;
        return 0;
    }
    if(r % 2 == 0) {
        int ansL = divide(nodes[u].l, r/2);
        int ansR = divide(nodes[u].r, r/2);
        return ansL + ansR;
    } else {
        int ansL1 = divide(nodes[u].l, r/2);
        int ansR1 = divide(nodes[u].r, r-r/2);
        int ansL2 = divide(nodes[u].l, r-r/2);
        int ansR2 = divide(nodes[u].r, r/2);
        return min(ansL1 + ansR1, ansL2 + ansR2);
    }
}

int main() 
{
    cin >> str;
    build();
    // preOrder(1);
    int ans = divide(1, rcnt);
    if(ans >= 2000) {
        cout << "impossible";
        return 0;
    }
    cout << ans;
    return 0;
}