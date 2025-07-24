# buti

# T1

记搜好题。我的做法：先倒序处理每个点的询问有哪些，再正序推一遍，似乎很快。

# T2

每个 $f_i$ 一定从之前最近的 $f_i-1$ 转移过来最优，建一棵树，倒序推每个点答案: $ans_i=lstans_{f_i}-sz_{i}$。

# T3

[缺一分治](https://www.cnblogs.com/bloodstalk/p/17658428.html) 每个点存档，对点分治，左侧对右侧有贡献，右侧对左侧有贡献。

# T4

out。

## $\text{FWT}$ 子集卷积

[TJ](https://www.luogu.com.cn/article/xt9hh8pb)

这里的技巧： $i \cap j = \emptyset \Rightarrow |i|+|j|=|i\cap j|$。

让外层卷积满足 $|i|+|j|=|i\cap j|$，内层卷积满足 $k = j | i$，即可求出答案。
