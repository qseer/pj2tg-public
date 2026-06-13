#include <bits/stdc++.h>
using namespace std;

// 斗地主出牌：给定手牌，求最少出几手能出完
// 简化版：只考虑单张、对子、三张、炸弹、三带一、三带二、顺子(5张起)
// 状态设计：用 15 维数组 cnt[3..17] 记录每种牌的数量（3~17 对应 3,4,...,10,J,Q,K,A,2,小王,大王）

int cnt[20];  // 每种牌的数量
int ans;

// 检查是否还有手牌
bool empty()
{
    for(int i = 3; i <= 17; ++i)
        if(cnt[i] > 0) return false;
    return true;
}

void dfs(int step)
{
    if(step >= ans) return;  // 剪枝：已不优于当前最优解
    if(empty())
    {
        ans = step;
        return;
    }

    // 1. 出炸弹（4张相同）
    for(int i = 3; i <= 15; ++i)
    {
        if(cnt[i] >= 4)
        {
            cnt[i] -= 4;
            dfs(step + 1);
            cnt[i] += 4;
        }
    }

    // 2. 出王炸
    if(cnt[16] >= 1 && cnt[17] >= 1)
    {
        cnt[16]--; cnt[17]--;
        dfs(step + 1);
        cnt[16]++; cnt[17]++;
    }

    // 3. 出三张（可带牌，先只出纯三张）
    for(int i = 3; i <= 15; ++i)
    {
        if(cnt[i] >= 3)
        {
            cnt[i] -= 3;
            // 3a. 纯三张
            dfs(step + 1);
            // 3b. 三带一
            for(int j = 3; j <= 17; ++j)
            {
                if(j == i || cnt[j] < 1) continue;
                cnt[j]--;
                dfs(step + 1);
                cnt[j]++;
            }
            // 3c. 三带二
            for(int j = 3; j <= 15; ++j)
            {
                if(j == i || cnt[j] < 2) continue;
                cnt[j] -= 2;
                dfs(step + 1);
                cnt[j] += 2;
            }
            cnt[i] += 3;
        }
    }

    // 4. 出对子
    for(int i = 3; i <= 15; ++i)
    {
        if(cnt[i] >= 2)
        {
            cnt[i] -= 2;
            dfs(step + 1);
            cnt[i] += 2;
        }
    }

    // 5. 出单张
    for(int i = 3; i <= 17; ++i)
    {
        if(cnt[i] >= 1)
        {
            cnt[i]--;
            dfs(step + 1);
            cnt[i]++;
        }
    }

    // 6. 出顺子（5 张及以上连续单牌，2 和王不能参与）
    for(int start = 3; start <= 10; ++start)
    {
        for(int len = 5; start + len - 1 <= 14; ++len)
        {
            bool ok = true;
            for(int i = start; i < start + len; ++i)
                if(cnt[i] < 1) { ok = false; break; }
            if(!ok) break;  // 更长的一定也不合法
            for(int i = start; i < start + len; ++i) cnt[i]--;
            dfs(step + 1);
            for(int i = start; i < start + len; ++i) cnt[i]++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--)
    {
        memset(cnt, 0, sizeof(cnt));
        int n;
        cin >> n;
        for(int i = 1; i <= n; ++i)
        {
            int x, y;
            cin >> x >> y;  // x: 牌面值, y: 花色（本题忽略花色）
            if(x == 0)
            {
                // 王牌：1=小王, 2=大王
                if(y == 1) cnt[16]++;
                else cnt[17]++;
            }
            else if(x == 1) cnt[14]++;  // A
            else if(x == 2) cnt[15]++;  // 2
            else cnt[x]++;
        }
        ans = n;  // 最坏情况全单张出
        dfs(0);
        cout << ans;
        if(T) cout << "\n";
    }
    return 0;
}
