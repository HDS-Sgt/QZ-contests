# 钚锑

## T1

昨天刚讲过，直接反射容斥。

## T2

赛时想到两边 dp 然后合并，结果 WA30，正解是每个点判断左右两侧哪一边 $>$ 它的数少，然后移动至这一侧，距离就是 $>$ 它的数的数量。

## T3

sb 子任务捆绑，sb 大样例 （100 -> 0）

对于一棵基环树，求解每一个环中断开代价最小的边，这里不只是建另一条边的代价，还有减去断开这条边对于剪去“树枝”造成的影响。后者注意分类讨论。
