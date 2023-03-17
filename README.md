# BUAA_Calculation_method

![image.png](https://s2.loli.net/2023/03/10/3eEoTwCRrpI8hL5.png)
[图源 ろびぞう](https://www.pixiv.net/users/46764132)

给某某同学代做的北航作业。

好好学习了一些数学知识（bushi）

## Week 1 高斯消元法解线性方程组

[高斯消元法的知识](https://zh.wikipedia.org/wiki/%E9%AB%98%E6%96%AF%E6%B6%88%E5%85%83%E6%B3%95)

最终就是简单实现了一下，没什么好说的。

## Week 2 LU分解法求解矩阵

LU分解法是一种常用的线性代数方法，在求解矩阵方程、解线性方程组等问题时广泛应用。它将一个矩阵分解为一个下三角矩阵L和一个上三角矩阵U的乘积，即A=LU，然后通过前代和回代求解方程组，从而得到未知数的解。

下面列一些相关的链接和参考资料：

[LU分解 - 维基百科](https://zh.wikipedia.org/zh-hans/LU%E5%88%86%E8%A7%A3)

[LU分解的原理及其应用 - 知乎](https://zhuanlan.zhihu.com/p/156544816)

[LU分解及其应用 - CSDN ](https://blog.csdn.net/weixin_42128971/article/details/105122424)

[Python实现LU分解法 - GitHub](https://github.com/Ransom767/Python-LU-decomposition)

[MATLAB实现LU分解法 - MathWorks](https://www.mathworks.com/help/matlab/ref/lu.html)


## Week 3 追赶法求解方程组

追赶法（又称扫描法或逐步消去法）是一种针对三对角矩阵（即对角线和其相邻的两条对角线上有数的矩阵）的线性方程组的求解方法。它是一种基本的数值分析方法，用于解决同步矩阵方程的数值解析问题。以下是一些参考资料和简单的讲解：

[追赶法的基本原理](https://blog.csdn.net/u010450214/article/details/50170623)，即矩阵的LU分解，以及如何利用LU分解求解三对角方程组。它还给出了一个具体的例子和MATLAB代码。
[详解追赶法](https://zhuanlan.zhihu.com/p/307876170)，并给出了伪代码和Python代码。它还提到了追赶法在有限差分格式中的应用。
[知乎问答-数值分析追赶法的由来](https://www.zhihu.com/question/386253562)，它探讨了追赶法这个名称的由来，以及它与LU分解的关系。它还展示了一个使用追赶法求解五对角方程组的例子。

