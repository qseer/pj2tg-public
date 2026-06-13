#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int n;
vector<ull> a;
ull s;
vector<int> ans;
unordered_map<ull, string> mp;
int mid;
string path;
void dfs1(int i, ull sum) {
    if (i == mid) {
        mp[sum] = path;
        return;
    }
    path.push_back('0');
    dfs1(i + 1, sum);
    path.pop_back();
    path.push_back('1');
    dfs1(i + 1, sum + a[i]);
    path.pop_back();
}
bool dfs2(int i, ull sum) {
    if (i == n) {
        if (mp.count(s - sum)) {
            string res = mp[s - sum] + path;
            ans.clear();
            for (char c : res) ans.push_back(c - '0');
            return true;
        }
        return false;
    }
    path.push_back('0');
    if (dfs2(i + 1, sum)) return true;
    path.pop_back();
    path.push_back('1');
    if (dfs2(i + 1, sum + a[i])) return true;
    path.pop_back();

    return false;
}

int main() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> s;

    mid = n / 2;
    dfs1(0, 0);
    dfs2(mid, 0);

    for (int x : ans) cout << x;
    cout << endl;
    return 0;
}