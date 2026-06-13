#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n, m;
bool vis[maxn];

struct Node {
    int nxt; // 下一个节点的编号
    int pre; // 上一个节点的编号
}a[maxn];

// 在 x 的右边插入新元素 p
void addRight(int x, int p) 
{
    // left -> x -> right
    // left -> x -> p -> right
    int right= a[x].nxt;
    a[x].nxt = p;
    a[p].pre = x;
    a[p].nxt = right;
    a[right].pre = p;
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
    // 1. 初始化，1 号同学在队列，初始化前驱和后继的元素为空元素，使用编号 0 表示
    a[0].nxt = 1;
    a[1].nxt = 0;
    a[1].pre = 0;
    for(int i=2; i<=n; ++i) {
        int p, k; cin >> k >> p;
        if(p == 1) {
            // 在 k 的右边插入 i 号同学
            addRight(k, i);
        }
        else {
            // 在 k 的左边插入 i 号同学
        }
    }
    for(int i=a[0].nxt; i!=0; i=a[i].nxt) 
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