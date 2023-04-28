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

int isEmpty(){
    return front == rear;
}

int isFull(){
    return front == (rear+1) % MAX;
}
//queue

int main(){
    int stu, sand, temp, time = 0;
    int sandwiches[MAX], top = 0;

    scanf("%d", &sand);
    for(int i = 0; i < sand; i++)
        scanf("%d", &sandwiches[i]);
    
    scanf("%d", &stu);
    for(int j = 0; j < stu; j++){
        scanf("%d", &temp);
        if(!isFull())
            enqueue(temp);
        else{
            printf("Queue overflow");
            return 0;
        }
    }

    while(!isEmpty()){
        time++;
        temp = dequeue();
        if(temp == sandwiches[top])
            top++;
        else
            enqueue(temp);
    }

    printf("time: %d", time);
}