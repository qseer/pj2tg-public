#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
int n;
string str;

int main() 
{
    cin >> n; cin >> str;
    ll up = 0, down = 0;
    for(int i=0; i<str.length(); ++i) {
        if(str[i] == '-') up ++;
        else if(str[i] == '_') down ++;
    }
    ll ans = down * (up/2) * (up - up/2);
    cout << ans;
}