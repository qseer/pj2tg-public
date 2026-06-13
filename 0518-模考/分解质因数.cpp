#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

int main() 
{
    // 1. 判断质数
    int n = 22; // 2 11
    // 枚举的因数范围 2 ~ sqrt(n)
    for(int i=2; i*i<=n; ++i) 
    {
        if(n % i == 0) // i 一定是质数      如果 i 是合数，4 = 2 * 2
        {
            // i 一定是质因数
            while(n % i == 0) {
                tong[i] ++;
                n /= i;
            }
        }
    }
    // 特判一下，最后可能剩下的，这个一次方的最大的质因子
    if(n > 1) 
    {
        tong[n] ++;
    }

}