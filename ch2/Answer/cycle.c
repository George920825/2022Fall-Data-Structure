#include <stdio.h>

int array[10]={1,2,3,4,5,6,7,8,9,10};

void m();
int main() 
{
	printf("��l�}�C:");
	for(int i=0;i<10;i++)
		printf("%2d ",array[i]);
	printf("\n");
		
	m();
	printf("�`���@����:");
	for(int i=0;i<10;i++)
		printf("%2d ",array[i]);
	printf("\n");
	
	m();
	printf("�`���⦸��:");
	for(int i=0;i<10;i++)
		printf("%2d ",array[i]);
	printf("\n");
	
	m();
	printf("�`���T����:");
	for(int i=0;i<10;i++)
		printf("%2d ",array[i]);
		
	
}

void m(){
	int temp=array[9];
	for(int i=8;i>=0;i--)
		array[i+1]=array[i];
	array[0]=temp;
}

