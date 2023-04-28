#include <stdio.h>

void left();
int Num[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

int main ()
{
    
    printf("?原始陣列:");
    for ( int i = 0; i < 10; i++ )
        printf("%3d", Num[i]);
    printf("\n");

    left();
    printf("循環一次後:");
    for ( int i = 0; i < 10; i++ )
        printf("%3d", Num[i]);
    printf("\n");

    left();
    printf("循環兩次後:");
    for ( int i = 0; i < 10; i++ )
        printf("%3d", Num[i]);
    printf("\n");
    
    left();
    printf("循環三次後:");
    for ( int i = 0; i < 10; i++ )
        printf("%3d", Num[i]);
    printf("\n");
}

void left ()
{
    int l = Num[9];
    for ( int i = 9; i > 0; i-- )
        Num[i]=Num[i-1];
    Num[0] = l;
}