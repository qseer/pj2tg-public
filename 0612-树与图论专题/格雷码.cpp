#include <iostream>
#include <cmath>
using namespace std;
int n, k;
const int maxn = 5e6 + 10;
string str[maxn];

void addPre(int len) {
    for(int i=len/2+1, j=len/2; i<=len; ++i, --j) {
        str[i] = "1" + str[j];
    }
    for(int i=1; i<=len/2; ++i) {
        str[i] = "0" + str[i];
    }
}

int main()
{
    cin >> n >> k;
    int len = 1; // 1 bit 
    str[1] = "0";
    str[2] = "1";
    for(int i=2; i<=n; ++i) {
        len = pow(2, i);
        addPre(len);
    }
    // for(int i=1; i<=len; ++i) {
    //     cout << str[i] << endl;
    // }
    cout << str[k+1];
    return 0;
}