// 使用追赶法求解线性方程组
#include <stdio.h>
#include <stdlib.h>
#include "math.h"

double **A, *b, *x, *y, **L, **U;
unsigned int RANK = 4;
void Init_Matrix(unsigned int r)
{
    // 分配A, L, U三个矩阵的内存空间，以及初始化为0
    A = (double **)malloc(sizeof(double *) * r);
    for (int i = 0; i < r; i++)
        A[i] = (double *)malloc(sizeof(double) * r);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
            A[i][j] = 0.0;
    }
    L = (double **)malloc(sizeof(double *) * r);
    for (int i = 0; i < r; i++)
        L[i] = (double *)malloc(sizeof(double) * r);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
            L[i][j] = 0.0;
    }
    U = (double **)malloc(sizeof(double *) * r);
    for (int i = 0; i < r; i++)
        U[i] = (double *)malloc(sizeof(double) * r);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
            U[i][j] = 0.0;
    }
}

void Init()
{
    unsigned int r;

    printf("Please input the rank of the matrix:\n");
    scanf_s("%d", &r);

    Init_Matrix(r);

    // 分配b, x, y三个向量的内存空间，以及初始化为0
    b = (double *)malloc(sizeof(double) * r);
    for (int i = 0; i < r; i++)
    {
        b[i] = 0.0;
    }
    x = (double *)malloc(sizeof(double) * r);
    for (int i = 0; i < r; i++)
    {
        x[i] = 0.0;
    }
    y = (double *)malloc(sizeof(double) * r);
    for (int i = 0; i < r; i++)
    {
        y[i] = 0.0;
    }
    RANK = r;
}

void Get_Matrix()
{
    // 读入系数矩阵A和向量b
    printf("Please input the coefficient matrix:\n");
    for (int i = 0; i < RANK; i++)
    {
        for (int j = 0; j < RANK; j++)
        {
            scanf("%lf", &A[i][j]);
        }
    }
    printf("Please input the vector:\n");
    for (int i = 0; i < RANK; i++)
    {
        scanf_s("%lf", &b[i]);
    }
    printf("\n");
}

// 追赶法解线性方程组
void LUrush_calculation()
{
    L[0][0] = 1; // L和U矩阵的初始化
    U[0][0] = A[0][0];
    for (int i = 1; i < RANK; i++) // 进行LU分解
    {
        L[i][i] = 1;                                   // L矩阵的对角线元素均为1
        L[i][i - 1] = A[i][i - 1] / U[i - 1][i - 1];   // 计算L矩阵的非对角线元素
        U[i - 1][i] = A[i - 1][i];                     // 计算U矩阵的非对角线元素
        U[i][i] = A[i][i] - L[i][i - 1] * U[i - 1][i]; // 计算U矩阵的对角线元素
    }
    y[0] = b[0]; // 计算y向量
    for (int i = 1; i < RANK; i++)
    {
        y[i] = b[i] - L[i][i - 1] * y[i - 1]; // 计算y向量
    }
    x[RANK - 1] = y[RANK - 1] / U[RANK - 1][RANK - 1]; // 计算解向量的最后一项
    for (int i = RANK - 2; i >= 0; i--)                // 通过回带法求解x向量
    {
        x[i] = (y[i] - A[i][i + 1] * x[i + 1]) / U[i][i];
    }
    for (int i = 0; i < RANK; i++) // 输出解向量
    {
        printf("x%d = %g\n", i + 1, x[i]);
    }
}

int main()
{
    Init();
    Get_Matrix();
    LUrush_calculation();

    return 0;
}
