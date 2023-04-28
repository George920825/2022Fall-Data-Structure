#include <stdio.h>
#define MAX 100
using namespace std;

//queue
char queue[MAX];
int rear = MAX-1, front = MAX-1;

void enqueue(char item){
    rear = (rear+1) % MAX;
    if (rear == front)
        printf("The queue is full.");
    else
        queue[rear] = item;
}

char dequeue(){
    if (front == rear){
        printf("The queue is empty.");
        return 0;
    }
    else{
        front = (front+1) % MAX;
        return queue[front];
    }
    
}

int qisEmpty(){
    return front == rear;
}

int qisFull(){
    return front == (rear+1) % MAX;
}
//queue
//stack
char stack[MAX];
int top = -1;

int sisEmpty(){
    if (top == -1)
        return 1;
    else
        return 0;
}

int sisFull(){
    if (top == MAX-1)
        return 1;
    else
        return 0;
}

char pop(){
    if (sisEmpty()){
        printf("The stack is empty.");
        return 0;
    }
    else
        return stack[top--];
}        

void push(char a){
    if (sisFull())
        printf("The stack is full.");
    else
        stack[++top] = a;
}

char topItem(){
    if (sisEmpty()){
        printf("The stack is empty.");
        return 0;
    }
    else
        return stack[top];
}
//stack


int main(){
    int stu, sand, temp, time = 0;
    int sandwiches[MAX], top = 0;

    scanf("%d", &sand);
    for(int i = 0; i < sand; i++){
        scanf("%d", &temp);
        if(!sisFull())
            push(temp);
        else{
            printf("Stack overflow");
            return 0;
        }
    }
    
    scanf("%d", &stu);
    for(int j = 0; j < stu; j++){
        scanf("%d", &temp);
        if(!qisFull())
            enqueue(temp);
        else{
            printf("Queue overflow");
            return 0;
        }
    }

    while(!qisEmpty()){
        time++;
        temp = dequeue();
        switch (temp)
        {
        case 0:
            if(topItem() != 0)
                enqueue(temp);
            else
                pop();
            break;
        case 1:
            if(topItem() != 1)
                enqueue(temp);
            else
                pop();
            break;
        case 2:
            push(0);
            break;
        case 3:
            push(1);
            break;
        case 4:
            pop();
            pop();
            break;
        default:
            break;
        }
    }

    printf("time: %d", time);
}