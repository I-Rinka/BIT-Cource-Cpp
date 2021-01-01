#include <stdio.h>
#include <stdlib.h>

int pic_m = 0;
int pic_n = 0;

int kernel_u = 0;
int kernel_v = 0;

int GetPicNum(int *pic_addr, int row_limit, int col_limit, int row, int col)
{
    if (row < 0 || col < 0 || row >= row_limit || col >= col_limit)
    {
        return 0;
    }
    return pic_addr[row * col_limit + col];
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &pic_m, &pic_n);
    scanf("%d %d", &kernel_u, &kernel_v);

    int *pic_addr = (int *)calloc(sizeof(int), pic_m * pic_n);
    double *kernel_addr = (double *)calloc(sizeof(double), kernel_u * kernel_v);

    for (int i = 0; i < pic_m; i++)
    {
        for (int j = 0; j < pic_n; j++)
        {
            scanf("%d", &pic_addr[i * pic_n + j]);
        }
    }

    for (int i = 0; i < kernel_u; i++)
    {
        for (int j = 0; j < kernel_v; j++)
        {
            scanf("%lf", &kernel_addr[i * kernel_v + j]);
        }
    }

    /*
    for (int i = 0; i < pic_m; i++)
    {
        for (int j = 0; j < pic_n; j++)
        {
            printf("%d ", pic_addr[i * pic_n + j]);
        }
        printf("\n");
    }
    检测图像输入
    */

    /*
    for (int i = 0; i < kernel_u; i++)
    {
        for (int j = 0; j < kernel_v; j++)
        {
            printf("%.4lf ", kernel_addr[i * kernel_u + j]);
        }
        printf("\n");
    }
    检测卷积核输入
    */

    int middle_u = kernel_u / 2, middle_v = kernel_v / 2;
    for (int i = 0; i < pic_m; i++)
    {
        for (int j = 0; j < pic_n; j++)
        {
            int ans = 0;
            for (int i2 = -middle_u; i2 <= middle_u; i2++)
            {
                for (int j2 = -middle_v; j2 <= middle_v; j2++)
                {
                    double temp = kernel_addr[(i2 + middle_u) * kernel_v + (j2 + middle_v)] * GetPicNum(pic_addr, pic_m, pic_n, i + i2, j + j2);
                    if (temp >= 0)
                    {
                        ans += (int)(temp + 0.5);
                    }
                    else
                    {
                        ans += (int)(temp - 0.5);
                    }
                }
            }
            printf("%d ", ans);
        }
        printf("\n");
    }

    return 0;
}
