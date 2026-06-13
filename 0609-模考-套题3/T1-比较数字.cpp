#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

int main() 
{
    // freopen("A.in", "r", stdin);
    // freopen("A.out", "w", stdout);
    string n; cin >> n;
    int len = n.length();
    bool flag = false;
    for(int i=0; i<len; ++i) 
    {
        if(flag) 
        {
            cout << '1';
        }
        else if(n[i] == '0') 
        {
            flag = true;
            cout << '1';
        }
        else 
        {
            cout << n[i];
        }
    }
    return 0;
}