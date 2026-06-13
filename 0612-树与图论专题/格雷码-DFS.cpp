#include <iostream>
#include <cmath>
#define LL unsigned long long 
using namespace std;

string dfs(LL n, LL k) {
    // 求长度为 n 的第 k 个，回溯到：
    // 1. “0” + 长度为 n-1 的第几个；
    // 2. “1” + 长度为 n-1 的第几个；
    if(n == 1) {
        if(k == 0) return "0";
        return "1";
    }
    LL half = pow(2, n-1); // 0 ~ 2^n-1
    if(k < half) return "0" + dfs(n-1, k);
    return "1" + dfs(n-1, (half-1)-(k-half)); // 倒数第 k-half 个
}

int main()
{
    LL n, k;
    cin >> n >> k;
    cout << dfs(n, k);
    return 0;
}