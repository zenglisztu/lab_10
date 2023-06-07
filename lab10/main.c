#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int **creat_2darr(int row, int col);
int free_2darr(int **arr, int row, int col);
int **input_2darr(int **arr, int row, int col);
void print_arr_T(int **arr, int row, int col);
int main(int argc, char *argv[])
{
    int n = 0;
    int row = 0;
    int col = 0;
    int ** _2darr = NULL;
    scanf("%d", &n);
    while(n)
    {   scanf("%d", &row);
        scanf("%d", &col);
        _2darr = creat_2darr(row, col);
        print_arr_T(input_2darr(_2darr, row, col), row, col);
        n--;
    }

    //system("pause");
    return 0;
}
int **input_2darr(int **arr, int row, int col)
{
    int i = 0;
    int j = 0;
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    return arr;
}

int **creat_2darr(int row, int col)
{
    int **arr = NULL;
    int i = 0;
    arr = (int **)malloc(row * sizeof(int*));
    for(i = 0; i < row; i++)
    {
        arr[i] = (int *)malloc(col * sizeof(int));
        memset(arr[i], 0, col * sizeof(int));
    }
    return arr;
}
int free_2darr(int **arr, int row, int col)
{
    int i = 0;
    for(i = 0; i < row; i++)
    {
        free(arr[i]);
    }
    free(arr);
    arr = NULL;
    return 0;
}

void print_arr_T(int **arr, int row, int col)
{
    int i = 0;
    int j = 0;
    for(i = 0; i < col; i++)
    {
        for(j = 0; j < row; j++)
        {
            printf("%d",arr[j][i]);
            if(j < row - 1)
            {
                printf(" ");
            }
            else
            {
                printf("\n");
            }
        }
    }
    free_2darr(arr, row, col);
}