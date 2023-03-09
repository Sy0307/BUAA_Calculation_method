#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 50

void swap(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n; // 矩阵的大小
    double A[MAX_SIZE][MAX_SIZE], b[MAX_SIZE], x[MAX_SIZE];

    printf("Matrix Size：");
    scanf("%d", &n);

    printf("Matrix Input:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            scanf("%lf", &A[i][j]);
        }
    }

    // 列主元高斯消去法
    for (int k = 0; k < n - 1; k++)
    {
        // 部分选主元
        double max = fabs(A[k][k]); // 假定当前行的第 k 个元素为最大值
        int max_row = k;            // 最大值所在的行为 k
        for (int i = k + 1; i < n; i++)
        {
            if (fabs(A[i][k]) > max) // 如果当前行的第 k 个元素不是最大值
            {
                max = fabs(A[i][k]); // 更新最大值
                max_row = i;         // 更新最大值所在的行
            }
        }
        if (max_row != k) // 如果最大值所在的行不是当前行
        {
            for (int j = k; j <= n; j++) // 交换当前行和最大值所在的行
            {
                swap(&A[k][j], &A[max_row][j]);
            }
        }

        for (int i = k + 1; i < n; i++) // 高斯消元
        {
            double factor = A[i][k] / A[k][k]; // 计算消元因子
            for (int j = k; j <= n; j++)
            {
                A[i][j] = A[i][j] - factor * A[k][j]; // 消元
            }
        }
    }

    // 回带求解
    x[n - 1] = A[n - 1][n] / A[n - 1][n - 1]; // 求解最后一个未知数
    for (int i = n - 2; i >= 0; i--)          // 从倒数第二个未知数开始
    {
        double sum = 0;
        for (int j = i + 1; j < n; j++)
        {
            sum += A[i][j] * x[j]; // 计算已知的未知数对应的系数与已知的未知数的乘积之和
        }
        x[i] = (A[i][n] - sum) / A[i][i]; // 求解未知数
    }

    printf("Answer：\n");
    for (int i = 0; i < n; i++)
    {
        printf("x[%d] = %lf\n", i, x[i]); // 输出结果
    }

    return 0;
}