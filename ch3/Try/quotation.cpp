#include <stdio.h>
#define MAX 100
using namespace std;

//stack
char stack[MAX];
int top = -1;

int isEmpty(){
    if (top == -1)
        return 1;
    else
        return 0;
}

int isFull(){
    if (top == MAX-1)
        return 1;
    else
        return 0;
}

char pop(){
    if (isEmpty()){
        printf("The stack is empty.");
        return 0;
    }
    else
        return stack[top--];
}        

void push(char a){
    if (isFull())
        printf("The stack is full.");
    else
        stack[++top] = a;
}

char topItem(){
    if (isEmpty()){
        printf("The stack is empty.");
        return 0;
    }
    else
        return stack[top];
}
//stack

int main (){
    char input[MAX];
    scanf("%s", &input);
    for (int i = 0; input[i] != '\0'; i++){
        switch (input[i])
        {
        case '{':
        case '[':
        case '(':
            if(!isFull())
                push(input[i]);
            else{
                printf("Stack overflow");
                return 0;
            }
            break;
        case '}':
            if(isEmpty()){
                printf("Not good");
                return 0;
            }
            if(pop() != '{'){
                printf("Not good");
                return 0;
            }
            break;
        case ']':
            if(isEmpty()){
                printf("Not good");
                return 0;
            }
            if(pop() != '['){
                printf("Not good");
                return 0;
            }
            break;
        case ')':
            if(isEmpty()){
                printf("Not good");
                return 0;
            }
            if(pop() != '('){
                printf("Not good");
                return 0;
            }
            break;

        default:
            break;
        }
    }
    if(isEmpty())
        printf("Good");
    else
        printf("Not good");
    return 0;
}