#include <stdio.h>

int array[10]={1,2,3,4,5,6,7,8,9,10};

void m();
int main() 
{
	printf("原始陣列:");
	for(int i=0;i<10;i++)
		printf("%2d ",array[i]);
	printf("\n");
		
	m();
	printf("循環一次後:");
	for(int i=0;i<10;i++)
		printf("%2d ",array[i]);
	printf("\n");
	
	m();
	printf("循環兩次後:");
	for(int i=0;i<10;i++)
		printf("%2d ",array[i]);
	printf("\n");
	
	m();
	printf("循環三次後:");
	for(int i=0;i<10;i++)
		printf("%2d ",array[i]);
		
	
}

void m(){
	int temp=array[9];
	for(int i=8;i>=0;i--)
		array[i+1]=array[i];
	array[0]=temp;
}

