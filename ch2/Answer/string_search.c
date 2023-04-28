#include <stdio.h>
#include <stdbool.h>
#define NUM 5

char *zoo[NUM]={"bear","lion","gorilla","kangaroo","raccoon"};
char *animal="gorilla";
	
void str_search(char *a[], char *k);
void arr_print(char *a[]);

int main()
{
	// show store position 
//	for (int i;i<5;i++)
//		printf("%s : %p\n",zoo[i],zoo[i]);
	
	// print array element
	arr_print(zoo);
	
	// string search
	char *animal="gorilla";	
	str_search(zoo, animal);
	
}

void arr_print(char *arr[]){
	printf("%s\n","Animals:");
	
	for(int i=0;i<NUM;i++)
		printf("%s \n",zoo[i]);
}

void str_search(char *arr[], char *key){
	
	printf("\n%s %s %s \n","Is",animal,"in the zoo?");
	
	bool exsist=false;
	
	for(int i=0;i<NUM;i++)
		if (arr[i]==key)
			exsist=true;
	
	if (exsist==false)
		printf("%s \n","No.");
	else
		printf("%s \n","Yes.");
}


