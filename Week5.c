#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 1000
#define MAX_SIZE 100
#define TOLERANCE 1e-6
double A[MAX_SIZE][MAX_SIZE];   // 系数矩阵
double b[MAX_SIZE];             // 常数向量
double x[MAX_SIZE] = {0.0};     // 初始解向量
double x_new[MAX_SIZE] = {0.0}; // 新的解向量
int i, j, k;
int n;
double sum1, sum2;
int main()
{ // 方程组的维数
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lf", &A[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &b[i]);
    }
    for (k = 0; k < MAX_ITERATIONS; k++)
    {
        // 求解新的解向量
        for (i = 0; i < n; i++)
        {
            sum1 = 0.0;
            sum2 = 0.0;
            for (j = 0; j < i; j++)
            {
                sum1 += A[i][j] * x_new[j];
            }
            for (j = i + 1; j < n; j++)
            {
                sum2 += A[i][j] * x[j];
            }
            x_new[i] = (b[i] - sum1 - sum2) / A[i][i];
        }

        // 判断是否达到精度要求
        double norm = 0.0;
        for (i = 0; i < n; i++)
        {
            norm += pow(x_new[i] - x[i], 2);
        }
        norm = sqrt(norm);
        if (norm < TOLERANCE)
        {
            printf("Solution converged after %d iterations:\n", k + 1);
            for (i = 0; i < n; i++)
            {
                printf("x[%d] = %f\n", i, x_new[i]);
            }
            return 0;
        }

        // 更新解向量
        for (i = 0; i < n; i++)
        {
            x[i] = x_new[i];
        }
    }

    printf("Solution did not converge after %d iterations.\n", MAX_ITERATIONS);
    return 0;
}