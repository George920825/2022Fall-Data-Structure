#include <stdio.h>
#include <stdbool.h>

void strSearch( char* [], char* );

int main()
{
    char* zoo[5] = { "bear", "lion", "gorilla", "kangaroo", "raccon" };
    char* animal = "gorilla";

    strSearch( zoo, animal );
}

void strSearch( char* arr[], char* key )
{
    bool find = false;
    
    for( int i = 0; i < 5; i++)
    {
        if( key == arr[i] )
            find = true;
    }

    if( find == false)
        printf("%s\n", "No.");
    else
        printf("%s\n", "Yes.");
}