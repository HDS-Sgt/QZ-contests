# clonoth-1

组合数： $\binom{n}{m}$ 表示从 $n$ 个不同的物品中选出 $m$ 个的方案数。

取补集： $\binom{n}{m} = \binom{n}{n-m}$。

通项公式： $\binom{n}{m} = \frac{n!}{m!(n-m)!}$。

递推式： $\binom{n}{m} = \binom{n-1}{m} + \binom{n-1}{m-1}$。

也是递推式： $\binom{n}{k} = \frac{n}{k}\binom{n-1}{k-1} = \frac{n-k+1}{k}\binom{n}{k-1}$。

多重组合数：
$$
\begin{pmatrix}
n \\
s_1, \ldots, s_k
\end{pmatrix}
$$
表示从 $n$ 个不同的物品中依次选

出不交的 $s_1, \ldots, s_k$ 个物品的方案数，其中 $\sum_{i=1}^k s_i = n$。
$$
\begin{pmatrix}
n \\
s_1, \ldots, s_k
\end{pmatrix} = \frac{n!}{\prod_{i=1}^k s_i!}
$$

容易发现
$$
\begin{pmatrix}
n \\
m
\end{pmatrix} = \begin{pmatrix}
n \\
m, n - m
\end{pmatrix}
$$

## 上指标求和

$$\sum_{i=m}^n \binom{i}{m} = \binom{n+1}{m+1}$$

证明：考虑将 $\binom{n+1}{m+1}$ 按照杨辉三角递推式展开。

或者也可以考虑 $S = 1, 2, \ldots, n+1$ 的 $m+1$  元子集数量。

$$\binom{n}{m}\binom{m}{k} = \binom{n}{k}\binom{n-k}{m-k}$$

考虑组合意义即可。

## 二项式定理

$$
(a+b)^n = \sum_{i=0}^n \binom{n}{i} a^{n-i} b^i.
$$
证明可以考虑组合意义或数学归纳法。

一些推论：
  
$$
\sum_{i=0}^n \binom{n}{i} = (1+1)^n = 2^n
$$
$$
\sum_{i=0}^n (-1)^i \binom{n}{i} = (1+(-1))^n = [n=0].
$$

上式指出对于 $n \ge 1$，从 $S = \{1, \ldots, n\}$ 选出大小为奇数的子集的方案数与选出大小为偶数的子集的方案数相同。

## 范德蒙德卷积

$$
\sum_{i=0}^k \binom{n}{i} \binom{m}{k-i} = \binom{n+m}{k}.
$$
证明考虑组合意义。

一些推论：
$$
\sum_{i=0}^s \binom{n}{r+i} \binom{m}{s-i} = \binom{n+m}{s+r}
$$
$$
\sum_{i=1}^n \binom{n}{i} \binom{n}{i-1} = \sum_{i=1}^n \binom{n}{n-i} \binom{n}{i-1} = \binom{2n}{n-1}
$$
$$
\sum_{i=0}^n \binom{n}{i}^2 = \sum_{i=0}^n \binom{n}{i} \binom{n}{n-i} = \binom{2n}{n}
$$
$$
\sum_{i=0}^m \binom{n}{i} \binom{m}{i} = \sum_{i=0}^m \binom{n}{i} \binom{m}{m-i} = \binom{n+m}{m}
$$

## 整数解问题

有 $k$ 个非负整数变量 $x_1, \ldots, x_k$ 要求 $x_1 + \cdots + x_k = n$。

解的数量 $\binom{n + k - 1}{n}$。

若每个整数变量有下界 $x_i \geq l_i$，可令 $n' = n - l_1 - \cdots - l_k$，

解的数量为 $\binom{n'+k - 1}{n'}$。

所以不失一般性，假设所有整数解问题中变量的下界都是 $0$。

若每个变量有上界 $x_i \leq r_i$，则可以通过容斥计算。

对于集合 $S \subseteq \{1,2, \ldots, k\}$，钦定 $\forall i \in S, x_i > r_i$，此时令
$
n' = n - \sum_{i \in S} (r_i + 1)$，计算，$x_1 + \cdots + x_k = n'$ 的解的数量即可。

注意容斥系数。

反射容斥用于处理一类不碰到直线 $y = x + b$ 的格路计数问题。

卡特兰数：从 $(0,0) \to (n,n)$ 不碰到 $y = x + 1$ 的方案数。

从 $(0,0)$ 到 $(n,n)$ 没有限制的方案数为 $\binom{2n}{n}$。

对于每一条碰到了 $y = x + 1$ 的路径，考虑将其从 $(0,0)$ 至第一次碰到的位置作关于 $y = x + 1$ 的对称，变为从 $(-1,1) \to (n,n)$ 的路径。

容易发现 $(-1,1) \to (n,n)$ 的路径与 $(0,0) \to (n,n)$ 碰到 $y = x + 1$ 的路径构成双射，所以原问题为
$$
\binom{2n}{n} - \binom{2n}{n - 1} = \binom{2n}{n} - \frac{n}{n + 1} \binom{2n}{n} = \frac{\binom{2n}{n}}{n + 1}
$$

推广：计算 $(0,0) \to (n,m)$ 不碰到 $L: y = x + l$ 和 $R: y = x + r$ 的方案数，其中 $l < 0 < r$。
对于路径定义由 $L, R$ 构成的字符串 $s_1, \ldots, s_k$ 表示依次碰到 $s_1, \ldots, s_k$，且 $s_i \neq s_{i=1}$，即连续两次碰到同一条线只算一次。

对于由 $L, R$ 构成的字符串 $S = s_1, \ldots, s_k$，定义 $f(S)$ 表示由路径定义的字符串以 $S$ 作为于串的路径数量。
那么原问题的答案为 $f(\empty) - f(L) - f(R) + f(LR) + f(RL) - f(RLR) + f(RLRL) - \cdots$。

在计算 $f(S)$ 时只需要将 $(0,0)$ 依次按照 $s_1, \ldots, s_k$ 对称即可，设最后得到的点为 $(x, y)$，计算 $(x, y) \to (n, m)$ 的方案数即可。

注意到不为 $0$ 的 $f(S)$ 数量为 $O(\frac{n + m}{r - l})$。

Lucas 定理：对于素数 $p$，有
$$
\binom{n}{m} \equiv \binom{\lfloor n/p\rfloor }{\lfloor m/p \rfloor} \binom{n \bmod p}{m \bmod p}\pmod p
$$

Lucas 定理指出，可以 $O(p)$ 预处理，$O(\log_pn)$ 求解：
$$
\binom{n}{m} \bmod p
$$

exLucas 可以求解一般的 $\binom{n}{m}$ mod $p$ 的值，而不要求 $p$ 是素数。

设 $p$ 的质因子分解为 $p = p_1^{\alpha_1} \ldots p_r^{\alpha_r}$，如果我们求出了
$$
\binom{n}{m} \bmod p_i^{\alpha_i}
$$
的值，则可以通过 CRT 进行合并。

问题转化为模数为 $p^k$ 的情形，其中 $p$ 为素数。

对于素数 $p$ 和正整数 $n$，将 $n!$ 中所有的因子 $p$ 都提取出来，可以得到分解 $n! = p^{n_p(n!)} (n!)_p$，其中 $p \nmid (n!)_p$。

由于 $\binom{n}{m} = \frac{n!}{m!(n-m)!}$，考虑分别求出
$$
\nu_p(n!), \nu_p(m!), \nu_p((n-m)!), (n!)_p, (m!)_p, ((n-m)!)_p,
$$
由于
$(n!)_p, (m!)_p, ((n-m)!)_p$ 均与 $p^k$ 互质，所有可以作除法。

问题转化为求解 $\nu_p(n!), (n!)_p \text{ mod } p^k$。

注意到 $\nu_p(n!) = \sum_{i=1}^n \nu_p(i) = \sum_{j \geq 1} \sum_{i=1}^n [\nu_p(i) \geq j] = \sum_{j \geq 1} \left[ n/p^j \right],$ 可以 $O(\log_p n)$ 计算。

对于  $(n!)_p \bmod p^k$，考虑提取所有 $p$ 的倍数并合并 $\bmod p^k$ 的循环节
$$(n!)_p \equiv \prod_{1 \leq i \leq n} i_p \equiv \prod_{1 \leq i \leq n, p \mid i} i_p \prod_{1 \leq i \leq n, p \nmid i} i_p \equiv (\lfloor n/p\rfloor!)_p \prod_{1 \leq i \leq n, p \nmid i} i \equiv (\lfloor n/p\rfloor !)_p \left( \prod_{1 \leq i < p^k, p \nmid i} i \right)^{|n/p^k|} \prod_{1 \leq i \leq n \bmod p^k, p \nmid i} i \pmod{p^k}
$$

在 $O(p^k)$ 预处理 $\large \forall 1 \leq s < p^k, \quad \prod_{1 \leq i \leq s \mod p^k, p \nmid i} i$ 后，可以 $O(\log_p n)$ 递归计算。

设 $p$ 的质因子分解为 $p = p_1^{\alpha_1} \cdots p_r^{\alpha_r}$，总时间复杂度为 $O(\sum_{i=1}^r p_i^{\alpha_i})$ 预处理， $O(\sum_{i=1}^r \log_{p_i} n)$ 处理单次询问。

小优化：
$$
\prod_{1 \leq i < p^k, p \nmid i} i \equiv \pm 1 \pmod{p^k}.
$$

Bonus：存在预处理时间复杂度为 $O(\sum_{i=1}^r \text{poly}(p_i, \alpha_i))$ 的算法。
