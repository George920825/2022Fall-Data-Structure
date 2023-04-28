#include<stdio.h>
#define SIZE 10

void swap(int*,int*);

int array[10] = {1,-2,-3,4,5,-6,-7,8,9,10};       //declare the input

int main(){
	int left=0,right=10-1;                        //left start from 0,right start from 9 
	while(left<right){                            //make sure right won't bigger than left and keep going until they meet
		while(array[left]<0&&left<10)             //while value < 0 left move to next value on right way
			left++;
		while(array[right]>0&&right>0)            //while value > 0 right move to next value on left way
			right--;
		if(left<right)	                          //make sure left is on the left side of right
			swap(&array[left],&array[right]);     //switch the values of left and right
		left++;                                   //after switching, left move to next value
		right--;                                  //after switching, right move to next value
		
	}
	for(int i=0;i<SIZE;i++)                       //print the output
		printf("%d ",array[i]);
	
	return 0;
} 

void swap(int *x,int *y){                        //define swap function
	int temp = *x;
	*x = *y;
	*y = temp;
}


