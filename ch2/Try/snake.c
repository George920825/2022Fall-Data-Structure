#include <stdio.h>

int main()
{
    int array[10][10];
    printf("原始陣列:\n");
    for( int i = 0; i < 10; i++ )
    {
        for( int j = 0; j < 10; j++ )
        {
            array[i][j] = i*10 + j+1;
            printf("%3d ", array[i][j]);
        }
        printf("\n");
    }

    printf("蛇行輸出:\n");
    for( int i = 0; i < 10; i++ )
    {
        for( int j = 0; j < 10; j++ )
        {
            if( i%2 == 0 )
                printf("%3d ", array[i][j]);
            else
                printf("%3d ", array[i][9-j]);
        }
        printf("\n");
    }
}