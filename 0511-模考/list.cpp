#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int N = 100;
struct Node {
    int pre, nxt;
}a[101];

int main() 
{
    a[1].pre = 0; // NULL 空元素，用编号 0 表示
    a[1].nxt = 0;
    a[0].nxt = 1;
    // 把插入操作实现出来：在 k 的后面插入 i
    // 在 1 的后面插入 5
    2 1 3
    2 1 5 3
    int right = a[1].nxt;
    a[1].nxt = 5;
    a[5].pre = 1;
    a[5].nxt = right;
    a[right].pre = 5;
    for(int i=a[0].nxt; i!=0; i=a[i].nxt) {
        cout << i << " ";
    }
}