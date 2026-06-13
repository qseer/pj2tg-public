#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

// 快速幂求模逆元
ll pw(ll a, ll b) {
    ll r = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) r = r * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, M;
    cin >> N >> M;

    // 边界:只有一个老师,他自己就是平均值,每种打分都贡献 1 次 bingo
    if (N == 1) {
        cout << (M + 1) % MOD << endl;
        return 0;
    }

    // 预处理阶乘的最大下标:
    // C(x(N-1) - j(M+1) + N-2, N-2), 上指标最大值在 x=M, j=0 时取到
    // 即 M(N-1) + N - 2
    ll max_val = M * (N - 1) + N - 2;

    vector<ll> fact(max_val + 1), inv_fact(max_val + 1);
    fact[0] = 1;
    for (ll i = 1; i <= max_val; i++)
        fact[i] = fact[i - 1] * i % MOD;
    inv_fact[max_val] = pw(fact[max_val], MOD - 2);
    for (ll i = max_val - 1; i >= 0; i--)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;

    // 组合数 C(n, k)
    auto C = [&](ll n, ll k) -> ll {
        if (n < 0 || k < 0 || n < k) return 0;
        return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
    };

    ll total = 0;

    // 枚举"中标"老师的得分 x:其他 N-1 个老师的分数和必须等于 x(N-1)
    for (ll x = 0; x <= M; x++) {
        ll f = 0;

        // 容斥:其余 N-1 个变量在 [0, M] 内、和为 x(N-1) 的非负整数解数
        for (ll j = 0; j <= N - 1; j++) {
            ll upper = x * (N - 1) - j * (M + 1) + (N - 2);
            // upper < N-2 时组合数为 0,且 j 增大只会让 upper 更小,可以提前退出
            if (upper < N - 2) break;

            ll term = C(N - 1, j) * C(upper, N - 2) % MOD;
            if (j & 1)
                f = (f - term + MOD) % MOD;
            else
                f = (f + term) % MOD;
        }

        total = (total + f) % MOD;
    }

    // N 个位置都可能是中标者,由对称性乘 N
    total = total * (N % MOD) % MOD;
    cout << total << endl;

    return 0;
}