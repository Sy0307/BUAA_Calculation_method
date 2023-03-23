#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100
#define EPS 1e-6 // 定义误差精度

int main()
{
    double a[N][N + 1]; // 定义系数矩阵和增广矩阵
    double x[N] = {0};  // 定义初始解向量
    double x0[N] = {0}; // 定义迭代解向量
    int i, j, k;        // 定义循环变量
    double max;         // 定义最大误差
    int n;

    // 输出原始增广矩阵
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            scanf("%lf", &a[i][j]);
        }
    }

    // 迭代求解
    k = 0;
    do
    {
        max = 0; // 初始化最大误差
        for (i = 0; i < n; i++)
        {
            x0[i] = a[i][n]; // 将常数向量赋值给迭代解向量
            for (j = 0; j < n; j++)
            {
                if (i != j)
                {
                    x0[i] -= a[i][j] * x[j]; // 更新迭代解向量
                }
            }
            x0[i] /= a[i][i];             // 求解第i个未知量的新解
            if (fabs(x0[i] - x[i]) > max) // 计算当前迭代的最大误差
            {
                max = fabs(x0[i] - x[i]);
            }
        }
        for (i = 0; i < n; i++)
        {
            x[i] = x0[i]; // 更新解向量
        }
        k++;                        // 迭代次数加1
    } while (max > EPS && k < 100); // 当误差小于精度或迭代次数超过100时结束迭代

    // 输出迭代结果
    printf("迭代结果为：\n");
    for (i = 0; i < n; i++)
    {
        printf("x%d=%.5lf\n", i + 1, x[i]);
    }

    return 0;
}