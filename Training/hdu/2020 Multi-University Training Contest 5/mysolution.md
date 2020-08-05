| Solved                                      | Pro.ID | Title                                                        | Ratio(Accepted / Submitted) |
| ------------------------------------------- | ------ | ------------------------------------------------------------ | --------------------------- |
| ![img](http://acm.hdu.edu.cn/images/ac.gif) | 1009   | [Paperfolding](http://acm.hdu.edu.cn/contests/contest_showproblem.php?pid=1009&cid=883) | 38.41%(583/1518)            |
| ![img](http://acm.hdu.edu.cn/images/ac.gif) | 1001   | [Tetrahedron](http://acm.hdu.edu.cn/contests/contest_showproblem.php?pid=1001&cid=883) | 37.54%(764/2035)            |
|                                             | 1003   | [Boring Game](http://acm.hdu.edu.cn/contests/contest_showproblem.php?pid=1003&cid=883) | 23.48%(363/1546)            |
|                                             | 1012   | [Set1](http://acm.hdu.edu.cn/contests/contest_showproblem.php?pid=1012&cid=883) | 22.87%(260/1137)            |
|                                             | 1007   | [Tree](http://acm.hdu.edu.cn/contests/contest_showproblem.php?pid=1007&cid=883) | 10.22%(120/1174)            |



## 1001

$a,b$和$c$互相垂直，设$a,b$和$c$的交点$D$到$∆ABC$的距离为$h$

求
$$
\frac1{h^2}\ mod\ 998244353
$$
思路：在$D$构建坐标系，得出面ABC的方程为：

由三点确定平面公式：
$$
{\displaystyle {\begin{vmatrix}x-x_{1}&y-y_{1}&z-z_{1}\\x_{2}-x_{1}&y_{2}-y_{1}&z_{2}-z_{1}\\x_{3}-x_{1}&y_{3}-y_{1}&z_{3}-z_{1}\end{vmatrix}}=0}
$$
代入：
$$
\begin{vmatrix}
        x-a & y & z \\
        -a & b & 0 \\
        -a & 0 & c \\
\end{vmatrix}=0
$$
即为$bcx+acy+abz-abc=0$

代入点到平面距离公式：
$$
{\displaystyle D={\frac {\left|ax_{1}+by_{1}+cz_{1}+d\right|}{\sqrt {a^{2}+b^{2}+c^{2}}}}}
$$
得到
$$
\frac1{h^2}=\frac1{a^2}+\frac1{b^2}+\frac1{c^2}
$$

## 1009

- 模拟一下可以看出水平对折和垂直对折的答案相对独立
- 对于$ x$ 次水平对折和$y$次垂直对折
- 答案是$(2^x + 1)(2^y + 1)$
- 因为通过反向逐操作还原，可以看到刀的痕迹的数量变化是每次在某一维倍增的
- 因此，相当于一张纸，水平和竖直分别切了$2^x,2^y$刀
- 所以数学期望为$ E(x) = \frac{1}{2^n}\sum_{i=0}^n C_n^i(2^i + 1)(2^{n-i} + 1) =1 + 2^n+2 \times 3^n/2^n$



## 1003

翻着翻着就完事了

## 1009

前（n-1)/2概率必是0

第(n+1)/2位：



1...(n-1)/2, (n+1)/2, ..., i-1,i,... n

$A_n^2*A_{n-2}^2...*A_{2}^2$ 
$$
cnt[i] = \binom{i-1}{n-i}\times(n-i)!\times \binom{2 \times i -n-1}{2,2,2,2,...2,2,2} \\


= \binom{i-1}{n-i}\times(n-i)!\times \frac{(2 \times i -n-1)!}{(2!)^{(2 \times i -n-1)/2}} \\
$$

$$
\frac{n!}{2^\frac{n}{2}}
$$

总方案数sum=\sigma cnt[i]

