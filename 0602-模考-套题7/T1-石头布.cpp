#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
string s;
int rock, paper;

int main() 
{
    cin >> s;
    int cnt = 0, ans = 0;
    for(char c: s) {
        if(cnt > 0) {
            if(c == 'g') ans ++;
            cnt --;
        } else {
            if(c == 'p') ans --;
            cnt ++;
        }
    }
    cout << ans;
    return 0;
}