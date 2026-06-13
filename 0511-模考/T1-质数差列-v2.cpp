#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX = 1e6;
long long n, cnt, p[MX], a[MX];
bool notPrime[MX + 10]; 

void init() 
{
    notPrime[0] = notPrime[1] = true;
    for(int i=2; i<=MX; ++i) 
    {
        if(notPrime[i] == false)  
        {
            p[++cnt] = i;
            for(ll j=(ll)i*i; j<=MX; j+=i) // 枚举所有质数的倍数
            {
                notPrime[j] = true;
            }
        }
    }
}

int main() 
{
    init();
    // printf("cnt=%lld\n", cnt);
    cin >> n;
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