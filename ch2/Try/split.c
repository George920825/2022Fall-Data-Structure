#include <stdio.h>

void swap( int *a, int *b );

int main()
{
    int array[10] = { 1, -2, -3, 4, 5, -6, -7, 8, 9, 10 };
    printf("��l�}�C : ");
    for( int i = 0; i < 10; i++ )
        printf("%d ", array[i]);
    printf("\n");
    
    int left = 0, right = 9;

    while(left < right)
    {
        while( array[left] < 0 && left < 10 )
            left++;
        while( array[right] > 0 && right > 0 )
            right--;
        if(left < right)
            swap( &array[right], &array[left] );
        left++;
        right--;
    }

    printf("�g�L�洫�� : ");
    for( int i = 0; i < 10; i++ )
        printf("%d ", array[i]);
    printf("\n");
}

void swap( int *a, int *b )
{
    int temp = *a;
    *a = *b;
    *b = temp;
}