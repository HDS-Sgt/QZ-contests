# 凸性优化

本专题并不全面讲解了凸性优化，但是作为入门，请放心食用。

## 决策单调性

### [POJ 3017 -- Cut the Sequence](http://poj.org/problem?id=3017)

- 将一个序列分成若干段，每段的和不超过给定值 $ M $，最小化每段的最大值之和。

### [CF321E Ciel and Gondolas - 洛谷](https://www.luogu.com.cn/problem/CF321E)

- 将 $ n $ 个人分成 $ k $ 组，最小化每组内冲突值之和 $\sum_{l\le i < j\le r}a_{i,j}$。

### [HDU Problem - 2829](https://acm.hdu.edu.cn/showproblem.php?pid=2829)

- 给定一个长度为 $ n $ 的序列 $ a_1, a_2, \dots, a_n $，你需要将其分成 $ m+1 $ 段（$ m $ 是给定的参数），每段的代价为该段内所有子序列的乘积之和。具体来说，设第 $ j $ 段的子序列为 $ a_{l_j}, a_{l_j+1}, \dots, a_{r_j} $，则该段的代价为：
  $$
  \sum_{l_j \leq s < t \leq r_j} a_s \cdot a_t
  $$
  总代价为所有段代价之和。你需要最小化这个总代价。

### [P1912 [NOI2009] 诗人小G - 洛谷](https://www.luogu.com.cn/problem/P1912)

- 给定一个长度为 $n$ 的序列 $a_1, a_2, \dots, a_n$ 和一个整数 $L$，你需要将其分成若干段，每段的代价为：
  $$
  \left| \left( \sum_{i=l_j}^{r_j} a_i \right) + (r_j - l_j) - L \right|^p
  $$

  其中 $p$ 是一个给定的常数。总代价为所有段代价之和。最小化总代价。

## 斜率优化：

### [P3195 [HNOI2008] 玩具装箱 - 洛谷](https://www.luogu.com.cn/problem/P3195)

- 给定一个长度为 $ n $ 的序列 $ c_1, c_2, \dots, c_n $ 和一个常数 $ L $，你需要将其分成若干段，每段的代价为：
  $$
  \left( \sum_{i=l_j}^{r_j} c_i + (r_j - l_j) - L \right)^2
  $$
  总代价为所有段代价之和。最小化总代价。

### [P3628 [APIO2010] 特别行动队 - 洛谷](https://www.luogu.com.cn/problem/P3628)

- 给定一个长度为 $ n $ 的序列 $ a_1, a_2, \dots, a_n $ 和三个常数 $ A,B,C $，你需要将其分成若干段，每段的代价为：
  $$
  A \left( \sum_{i=l_j}^{r_j} a_i \right)^2 + B \left( \sum_{i=l_j}^{r_j} a_i \right) + C
  $$
  总代价为所有段代价之和。最大化总代价。

## 李超线段树：

### [P5785 [SDOI2012] 任务安排 - 洛谷](https://www.luogu.com.cn/problem/P5785)

- 设 $ f_i $ 表示前 $ i $ 个任务的最小费用，转移方程为：
  $$
  f_i = \min_{0 \le j < i} \left\{ f_j + S \cdot \left( \sum_{k=j+1}^n c_k \right) + \left( \sum_{k=j+1}^i t_k \right) \cdot \left( \sum_{k=j+1}^i c_k \right) \right\}
  $$

## 打怪类的题目

### 前年暑期模拟赛的真题：

- 给定一棵 $n$ 个节点的有根树，除了根节点 $1$ 之外的每个节点上都有一个怪兽，打节点 $i$ 上的怪兽会先掉 $a_i$ 滴血，再恢复 $b_i$ 滴血。只有打掉了 $u$ 的所有祖先上的怪兽之后，才能打 $u$ 上的怪兽。问初始最少需要多少滴血才能打完所有怪兽。$n\le 10^5$。
- Hint：菊花怎么做？是否存在单调性？

### [HDU 7517](https://acm.hdu.edu.cn/showproblem.php?pid=7517)：

- 给定一个包含 $n$ 个二元组 $(a_i,b_i)$ 的双端队列，每次只能弹出队首或者队尾直到队列为空时停止。你有一个初始为 $0$ 的元素 $d,w$，每次弹出元素 $(a_i,b_i)$ 时，执行：$d\gets d+a_i,w\gets w +d\times b_i$。求出最终 $w$ 的最大值。$n\le 2\times 10^5$。
- Hint：如果可以任意选择一个顺序怎么做？是否存在单调性？

- 扩展题目：[Train Seats - Problem - QOJ.ac](https://qoj.ac/contest/1804/problem/9440)。
- 把元素全部改成怪物，改成打怪题呢？

### [LOJ #4256. 「KTSC 2024 R1」最大化平均值](https://loj.ac/p/4256)

- 题意好长，难以简化。
- Hint 1：合法的区间性质？
- Hint 2：是否存在单调性？

## 其他题目

### [CF GYM 102586B](https://codeforces.com/gym/102586/problem/B)

- 给定 $N,S$ 和 $a_{1\sim n}$，$a_i$ 表示 $i$ 号庇护所能容纳的人数，每次查询给出区间 $[l,r]$，你需要找到一个疏散成本最大的 $i\in[l,r]$。其中，对于区间 $[l,r]$，$i$ 的疏散成本是，假设初始 $S$ 个人都在 $i$，你需要把每个人安排进一个庇护所中（只考虑区间 $[l-1,r+1]$ 内的庇护所，并且设 $l-1$ 和 $r+1$ 庇护所能容纳无限个人），那么疏散成本是所有人移动距离的最小值。
- Hint 1：如何计算对于区间 $[l,r]$ 的 $i$ 的疏散成本？
- Hint 2：能否发现单调性？

### [CF GYM 102331J](https://codeforces.com/gym/102331/problem/J)

- 给定一棵 $n$ 个节点的树，每个节点有权值 $a_i$，对于 $k=0,1,\cdots ,n$，求出选择 $k$ 个互不相邻的点的权值和的最大值，或判断不存在任何一种方案。
- Hint：菊花怎么做？链怎么做？