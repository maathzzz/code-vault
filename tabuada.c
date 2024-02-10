#include <stdio.h>

int main()
{
    int matriz[10][10];
    int i = 0;
    int j = 0;
    
    for(i = 0 ; i <= 10; i++)
    {
        for(j = 0 ; j <= 10; j++)
        {
            matriz[i][j] = i * j;
            printf("%d x %d = %d\n",i,j, matriz[i][j]);
        }
        printf("\n");
    };

    return 0;
}