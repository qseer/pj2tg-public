#include <bits/stdc++.h>
using namespace std;

const int maxn = 10;

int g[maxn][maxn];
bool rowUsed[maxn][maxn];   // rowUsed[i][v]: 第 i 行是否已用数字 v
bool colUsed[maxn][maxn];   // colUsed[j][v]: 第 j 列是否已用数字 v
bool boxUsed[maxn][maxn];   // boxUsed[b][v]: 第 b 宫是否已用数字 v

// 将 (i,j) 映射到宫编号 0~8
inline int boxId(int i, int j)
{
    return (i - 1) / 3 * 3 + (j - 1) / 3;
}

bool dfs(int pos)
{
    if(pos > 81) return true;  // 全部填完
    int i = (pos - 1) / 9 + 1;
    int j = (pos - 1) % 9 + 1;
    if(g[i][j] != 0) return dfs(pos + 1);  // 已有数字，跳过

    int b = boxId(i, j);
    for(int v = 1; v <= 9; ++v)
    {
        // 行/列/宫剪枝：候选集过滤
        if(rowUsed[i][v] || colUsed[j][v] || boxUsed[b][v])
            continue;
        // 放置 v
        g[i][j] = v;
        rowUsed[i][v] = colUsed[j][v] = boxUsed[b][v] = true;
        if(dfs(pos + 1)) return true;
        // 回溯
        g[i][j] = 0;
        rowUsed[i][v] = colUsed[j][v] = boxUsed[b][v] = false;
    }
    return false;  // 无解
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 1; i <= 9; ++i)
        for(int j = 1; j <= 9; ++j)
        {
            cin >> g[i][j];
            if(g[i][j] != 0)
            {
                int v = g[i][j];
                int b = boxId(i, j);
                rowUsed[i][v] = colUsed[j][v] = boxUsed[b][v] = true;
            }
        }
    dfs(1);
    for(int i = 1; i <= 9; ++i)
    {
        for(int j = 1; j <= 9; ++j)
        {
            if(j > 1) cout << " ";
            cout << g[i][j];
        }
        cout << "\n";
    }
    return 0;
}
