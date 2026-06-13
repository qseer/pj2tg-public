#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n, m;
bool vis[maxn];

struct Node {
    int nxt, pre;
}a[maxn];

// 在 x 的右边插入新元素 p
void addRight(int x, int p) 
{
    int right = a[x].nxt;
    // 1. 先连哪些边？p -> right
    a[p].nxt = right;
    a[right].pre = p;
    // 2. 再连哪些边？x -> right
    a[x].nxt = p;
    a[p].pre = x;
}

void del(int x) 
{
    int left = a[x].pre;
    int right= a[x].nxt;
    // 删除 x，连两条边：
    // 1. left -> right
    // 2. right-> left
    a[left].nxt = right;
    a[right].pre= left;
}

int main() 
{
    cin >> n;
    // 1. 初始化链表，一开始只有 1 号同学，空节点的下一个指向 1 号同学
    a[1].nxt = 0; a[1].pre = 0; a[0].nxt = 1;
    // 2. 插入其余的 2 ~ n 的几位同学
    for(int i=2; i<=n; ++i) {
        int p, k; cin >> k >> p;
        if(p == 1) {
            // 在 k 的右边插入 i
            addRight(k, i);
        }
        else {
            // 在 k 的左边插入 i
            // 相当于在 k 的“原左元素“的右边插入 i
            addRight(a[k].pre, i);
        }
    }
    cin >> m;
    while(m--) 
    {
        int x; cin >> x;
        if(vis[x] == true) continue;
        del(x);
        vis[x] = 1;
    }
    for(int i=a[0].nxt; i; i=a[i].nxt) 
    {
        cout << i << " ";
    }
    return 0;
}
/* 
4
1 1
2 1
1 1
*/