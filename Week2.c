#include <stdio.h>
#include <stdlib.h>

// LU分解
void lu_decomposition(double **A, int n, int *p)
{
    int i, j, k, row;
    double max, tmp;

    // 初始化置换矩阵
    for (i = 0; i < n; i++)
    {
        p[i] = i;
    }

    // 进行LU分解
    for (k = 0; k < n - 1; k++)
    {
        // 选取绝对值最大的主元进行主元消去
        max = 0.0;
        for (i = k; i < n; i++)
        {
            if (abs(A[i][k]) > max)
            {
                max = abs(A[i][k]);
                row = i;
            }
        }

        // 如果主元为0，说明矩阵奇异，分解失败
        if (max == 0.0)
        {
            printf("Singular matrix\n");
            exit(1);
        }

        // 进行行交换
        if (row != k)
        {
            for (j = 0; j < n; j++)
            {
                tmp = A[k][j];
                A[k][j] = A[row][j];
                A[row][j] = tmp;
            }
            tmp = p[k];
            p[k] = p[row];
            p[row] = tmp;
        }

        // 进行消元操作
        for (i = k + 1; i < n; i++)
        {
            A[i][k] /= A[k][k];
            for (j = k + 1; j < n; j++)
            {
                A[i][j] -= A[i][k] * A[k][j];
            }
        }
    }
}

// 解线性方程组
void lu_solve(double **A, int n, double *b, int *p, double *x)
{
    int i, j;
    double s;

    // 前向替换
    for (i = 0; i < n; i++)
    {
        x[i] = b[p[i]];
        for (j = 0; j < i; j++)
        {
            x[i] -= A[i][j] * x[j];
        }
    }

    // 后向替换
    for (i = n - 1; i >= 0; i--)
    {
        s = x[i];
        for (j = i + 1; j < n; j++)
        {
            s -= A[i][j] * x[j];
        }
        x[i] = s / A[i][i];
    }
}

int main()
{
    int n, i, j, *p;
    double **A, *b, *x;

    // 获取矩阵大小
    printf("Enter number of Matrix Size: ");
    scanf("%d", &n);

    // 动态分配矩阵、向量及置换矩阵
    A = (double **)calloc(n, sizeof(double *));
    for (i = 0; i < n; i++)
    {
        A[i] = (double *)calloc(n, sizeof(double));
    }

    b = (double *)calloc(n, sizeof(double));
    x = (double *)calloc(n, sizeof(double));
    p = (int *)calloc(n, sizeof(int));


    printf("Enter the elements of the coefficient matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%lf", &A[i][j]);
        }
    }

    printf("Enter the elements of the constant vector:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%lf", &b[i]);
    }

    lu_decomposition(A, n, p);
    lu_solve(A, n, b, p, x);

    printf("\nSolution:\n");
    for (i = 0; i < n; i++)
    {
        printf("x%d = %lf\n", i + 1, x[i]);
    }

    for (i = 0; i < n; i++)
    {
        free(A[i]);
    }
    // 释放矩阵、向量及置换矩阵
    free(A);
    free(b);
    free(x);
    free(p);

    return 0;
}