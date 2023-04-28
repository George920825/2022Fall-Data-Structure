//1 1 2 3 5 8
#include <stdio.h>

int sol(int n){
    int s = 0;
    if(n > 0){
        switch (n)
        {
        case 1:
            s = 1;
            break;
        case 2:
            s = 1;
            break;
        default:
            s = sol(n-1)+sol(n-2);
            break;
        }
    }
    return s;
}

int main(){
    printf("%d", sol(20));
}