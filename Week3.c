// 使用追赶法求解线性方程组
#include <stdio.h>
#include <stdlib.h>
#include "math.h"

double **A, *b, *x, *y, **L, **U;
unsigned int RANK = 4;
void Init_Matrix(unsigned int r)
{
    A = (double **)malloc(sizeof(double *) * r); // 创建一个指针数组，把指针数组的地址赋值给a ,*r是乘以r的意思
    for (int i = 0; i < r; i++)
        A[i] = (double *)malloc(sizeof(double) * r); // 给第二维分配空间
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
            A[i][j] = 0.0;
    }
    L = (double **)malloc(sizeof(double *) * r); // 创建一个指针数组，把指针数组的地址赋值给a ,*r是乘以r的意思
    for (int i = 0; i < r; i++)
        L[i] = (double *)malloc(sizeof(double) * r); // 给第二维分配空间
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
            L[i][j] = 0.0;
    }
    U = (double **)malloc(sizeof(double *) * r); // 创建一个指针数组，把指针数组的地址赋值给a ,*r是乘以r的意思
    for (int i = 0; i < r; i++)
        U[i] = (double *)malloc(sizeof(double) * r); // 给第二维分配空间
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

void Get_Matrix() // 输入矩阵并呈现
{
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

void LUrush_calculation() // 追赶法解线性方程组
{
    L[0][0] = 1;
    U[0][0] = A[0][0];
    for (int i = 1; i < RANK; i++)
    {
        L[i][i] = 1;
        L[i][i - 1] = A[i][i - 1] / U[i - 1][i - 1];
        U[i - 1][i] = A[i - 1][i];
        U[i][i] = A[i][i] - L[i][i - 1] * U[i - 1][i];
    }
    y[0] = b[0];
    for (int i = 1; i < RANK; i++)
    {
        y[i] = b[i] - L[i][i - 1] * y[i - 1];
    }
    x[RANK - 1] = y[RANK - 1] / U[RANK - 1][RANK - 1];
    for (int i = RANK - 2; i >= 0; i--)
    {
        x[i] = (y[i] - A[i][i + 1] * x[i + 1]) / U[i][i];
    }
    for (int i = 0; i < RANK; i++)
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

/*

4 4
1 3 0 0
2 -1 3 0
0 3 2 5
0 0 -3 1
1 2 3 4


x1 = 2.19531
x2 = -0.398438
x3 = -0.929688
x4 = 1.21094


*/
