# 0612 树形 DP 专题题单

## 课程结构说明

| 环节 | 题目 | 定位 |
|------|------|------|
| 开场口头回顾（5 min） | LeetCode 198 打家劫舍 I | 不上机，显式挂出"选或不选"框架作为参照物 |
| 课内精讲 | P1352 没有上司的舞会 | 核心过渡题：数组 DP → 树上节点 DP |
| 课内精讲 | B4016 树的直径 | 递归结构相似但子问题独立，与 P1352 对比感受树形 DP vs 树上分治 |
| 课后作业 | P1122 最大子树和 | 融合前两道技巧，节点值有正有负；下节课开场讲解并引入下一专题 |

## 题目索引

| 题号 | 题目名称 | 链接 |
|------|----------|------|
| LeetCode 198 | 打家劫舍 | https://leetcode.cn/problems/house-robber/ |
| LeetCode 337 | 打家劫舍 III | https://leetcode.cn/problems/house-robber-iii/ |
| LeetCode 543 | 二叉树的直径 | https://leetcode.cn/problems/diameter-of-binary-tree/ |
| LeetCode 124 | 二叉树中的最大路径和 | https://leetcode.cn/problems/binary-tree-maximum-path-sum/ |
| P1352 | 没有上司的舞会 | https://www.luogu.com.cn/problem/P1352 |
| B4016 | 树的直径 | https://www.luogu.com.cn/problem/B4016 |
| P1122 | 最大子树和 | https://www.luogu.com.cn/problem/P1122 |
| P2016 | 战略游戏 | https://www.luogu.com.cn/problem/P2016 |

## CSES Tree Algorithms 备用题单

CSES 全部是一般树（非二叉树），与洛谷/LeetCode 形成互补；Tree Distances I → II 天然构成"发现换根DP"的教学序列。

| 教学阶段 | LeetCode | 洛谷 | CSES | 原链接 | VJudge（备用） |
|----------|----------|------|------|--------|----------------|
| 1. 锚点热身：子树遍历 | 198 打家劫舍 I | — | Subordinates | https://cses.fi/problemset/task/1674 | https://vjudge.net/problem/CSES-1674 |
| 2. 核心跨越：树形DP双状态 | 337 打家劫舍 III | P1352 没有上司的舞会 | Tree Matching | https://cses.fi/problemset/task/1130 | https://vjudge.net/problem/CSES-1130 |
| 3. 感受分治：子问题独立 | 543 二叉树的直径 | B4016 树的直径 | Tree Diameter | https://cses.fi/problemset/task/1131 | https://vjudge.net/problem/CSES-1131 |
| 4. 综合验证：舍弃负收益 | 124 二叉树最大路径和 | P1122 最大子树和 | Tree Distances I | https://cses.fi/problemset/task/1132 | https://vjudge.net/problem/CSES-1132 |
| 5. 进阶拓展：换根DP入门 | — | P2016 战略游戏 | Tree Distances II | https://cses.fi/problemset/task/1133 | https://vjudge.net/problem/CSES-1133 |

### 各题定位说明

- **Subordinates**：只需 DFS 统计子树大小，无复杂状态转移；让学生第一次感受"子节点汇总信息返回父节点"这个基本信息流。
- **Tree Matching**：每条边选或不选，相邻边不能同时选；在每个节点维护"是否已被匹配"两个状态，与 P1352 同构。
- **Tree Diameter**：与 B4016 完全等效；建议先写树形DP做法，再和 Tree Matching 对比感受"独立子问题"与"重叠子问题"的区别。
- **Tree Distances I**：每个节点求到所有其他节点的最大距离；最远距离可能经过父节点方向，需要先自底向上再自顶向下补充信息，是换根DP的天然入口。
- **Tree Distances II**：换根DP完整版，所有节点均需完成换根，是阶段5的拔高内容。
