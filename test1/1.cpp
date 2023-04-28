#include <stdio.h>

int main()
{
    int array[4][4];//= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

    for( int i = 0; i < 4; i++ )
        scanf("%d%d%d%d", &array[i][0], &array[i][1], &array[i][2], &array[i][3]);
    
    for( int i = 0; i < 4; i++ )
    {
        for( int j = 0; j < 4; j++ )
        {
            if(i%2 == 0 && j%2 == 0)
                printf("%3d ", array[i][j]);
            if(i%2 == 1 && j%2 == 1)
                printf("%3d ", array[i][j]);
        }
    }

    for( int i = 3; i >=0 ; i-- )
    {
        for( int j = 3; j >=0 ; j-- )
        {
            if(i%2 == 1 && j%2 == 0)
                printf("%3d ", array[i][j]);
            if(i%2 == 0 && j%2 == 1)
                printf("%3d ", array[i][j]);
        }
    }
}