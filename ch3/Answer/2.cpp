#include <stdio.h>
#define MAX 100
using namespace std;

//////////////////Queue/////////////////
int queue[MAX];
int front=0,rear=0;

int dequeue(){
	front=(front+1)%MAX;
	return queue[front];
}

void enqueue(int a){
	rear=(rear+1)%MAX;
	queue[rear]=a;
}

bool isempty(){
	return rear==front;
}

bool isfull(){
	return front==(rear+1)%MAX;
}
//////////////////Queue/////////////////
int main()
{
	int stu,sand,time=0;
	int sandwiches[MAX],top=0,temp;
	
	scanf("%d",&sand);//create sandwich stach
	for(int i=0;i<sand;i++)
		scanf("%d",&sandwiches[i]);
		
	scanf("%d",&stu);//create student queue
	for(int i=0;i<stu;i++){
		scanf("%d",&temp);
		if(!isfull())
			enqueue(temp);
		else{
			printf("Queue overflow!");
			return 0;
		}
	}
	while(!isempty()){
		time++;//count time
		
		temp=dequeue();//get one student out of queue
		
		if(sandwiches[top]==temp)//take one sandwich
			top++;
		else
			enqueue(temp);	//go back to queue		
	}
	printf("time : %d",time);

//	enqueue(0);
//	enqueue(1);
//	enqueue(2);
//	enqueue(3);
//	dequeue();
//	dequeue();
//	dequeue();
//	for(int i=(front+1)%MAX;i!=(rear+1)%MAX;i=(i+1)%MAX)
//		printf("%d",queue[i]);
}

//10
//0 1 1 0 0 1 1 1 0 1
//5
//1 0 1 0 0
//time : 8

//10
//1 0 0 1 0 0 1 0 0 1
//10
//0 1 0 0 1 0 1 1 0 0
//time : 16


