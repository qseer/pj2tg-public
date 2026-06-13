#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX = 1e7;
long long n, cnt, p[MX], a[MX];
bool notPrime[MX + 10]; // np[i] 初始都为 false，默认都不是质数，遇到合数 打上 true 的标记

void init() 
{
    for(int i=2; i<=MX; ++i) 
    {
        if(notPrime[i] == false)  
        {
            p[++cnt] = i;
            for(int j=i+i; j<=MX; j+=i) 
            {
                // 质数的倍数标记为 true
                notPrime[j] = true;
            }
        }
    }
}

int main() 
{
    cin >> n;
    init();
    printf("cnt=%lld\n", cnt);
    a[1] = p[n];
    long long sum = a[1];
    for(int i=2; i<=n; ++i) 
    {
        a[i] = a[i-1] + p[n-i+1];
        sum += a[i];
    }
    cout << sum;
    return 0;
}