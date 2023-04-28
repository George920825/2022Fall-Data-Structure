#include <stdio.h>
#include <stdlib.h>
#define MAX 50

char infix_q[MAX];
int compare(char stack_o, char infix_o);
void infix_to_postfix();

int main(){
    int i = 0;
    for(i = 0; i < MAX; i++)
        infix_q[i] = '\0';
    printf("\t-------------------------------\n");
    printf("\tinfix to postfix\n");
    printf("\tallow: ^, *, +, -, (, )??\n");
    printf("\t-------------------------------\n");
    printf("\tinfix: ");
    infix_to_postfix();
    printf("\n");
    printf("\t-------------------------------\n");
    system("pause");
    return 0;
}

int compare(char stack_o, char infix_o){
    char infix_priority[9];
    char stack_priority[8];
    int index_s=0, index_i=0;

    infix_priority[0]='q';infix_priority[1]='(';infix_priority[2]='+';infix_priority[3]='-';
    infix_priority[4]='*';infix_priority[5]='/';infix_priority[6]='^';infix_priority[7]=' ';
    infix_priority[8]=')';
    stack_priority[0]='q';stack_priority[1]='(';stack_priority[2]='+';stack_priority[3]='-';
    stack_priority[4]='*';stack_priority[5]='/';stack_priority[6]='^';stack_priority[7]=' ';

    while(stack_priority[index_s] != stack_o)
        index_s++;
    while(infix_priority[index_i] != infix_o)
        index_i++;
    if(index_s == 0 && index_i == 1)
        return 0;
    else
        return ((int)(index_s/2) >= (int)(index_i/2) ? 1 : 0);
}

void infix_to_postfix(){
    int rear = 0, top = 0, flag = 0, i = 0;
    char stack_t[MAX];
    for(i = 0; i < MAX; i++)
        stack_t[i] = '0';
    gets(infix_q);
    i = 0;
    while(infix_q[i] != '\0'){
        i++;
        rear++;
    }//count rear
    infix_q[rear] = 'q';
    printf("\tpostfix: ");
    stack_t[top] = 'q';
    for(flag = 0; flag <= rear; flag++){
        switch (infix_q[flag]){
            case ')':
                while(stack_t[top] != '(')
                    printf("%c", stack_t[top--]);
                top--;
                break;
            case 'q':
                while(stack_t[top] != 'q')
                    printf("%c", stack_t[top--]);
                break;
            case '(':
            case '^':
            case '*':
            case '/':
            case '+':
            case '-':
                while (compare(stack_t[top], infix_q[flag]))
                    printf("%c", stack_t[top--]);
                stack_t[++top] = infix_q[flag];
                break;
            default:
                printf("%c", infix_q[flag]);
                break;
        }
    }
}