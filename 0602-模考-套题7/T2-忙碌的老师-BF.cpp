#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxn = 1e5 + 10;
struct Node {
    int st, ed;
}classes[maxn];
int teacher[maxn];
int cnt;
priority_queue<int, vector<int>, greater<int>> q;

bool cmp(const Node &x, const Node &y) 
{
    return x.st < y.st;
}

void assign(int i)
{
    bool flag = false;
    for(int j=1; j<=cnt; ++j) {
        if(teacher[j] < classes[i].st) {
            flag = true;
            teacher[j] = classes[i].ed;
            break;
        }
    }
    if(flag == false) {
        ++cnt;
        teacher[cnt] = classes[i].ed;
    }
}

int main() 
{
    int n; cin >> n;
    for(int i=1; i<=n; ++i) {
        cin >> classes[i].st >> classes[i].ed;
    }
    sort(classes + 1, classes + 1 + n, cmp);
    q.push(classes[1].ed);
    for(int i=2; i<=n; ++i) {
        assign(i);
    }
    cout << q.size();
    return 0;
}