#include <stdio.h>
#define MAX 100
using namespace std;

/////////////STACK////////////////
char stack[MAX];
int top=0;

char pop(){
	return stack[--top];
}

void push(char a){
	stack[top++]=a;
}

bool isempty(){
	return top==0;
}

bool isfull(){
	return top==MAX-1;
}
/////////////STACK////////////////
int main()
{
	char input[MAX];
	char c;
	scanf("%s",&input);
	for(int i=0;input[i]!='\0';i++){
		switch(input[i]){
			case '[':
			case '{':
			case '(':
				if(!isfull())
					push(input[i]);
				else{
					printf("Stack overflow!");
					return 0;
				}				
				break;
			case ']':
				if(isempty()){
					printf("Not good!");
					return 0;
				} 
				c=pop();
				if(c!='['){
					printf("Not good!");
					return 0;	
				}
				break;
			case '}':
				if(isempty()){
					printf("Not good!");
					return 0;
				}
				c=pop();
				if(c!='{'){
					printf("Not good!");
					return 0;	
				}
				break;
			case ')':
				if(isempty()){
					printf("Not good!");
					return 0;
				}
				c=pop();
				if(c!='('){
					printf("Not good!");
					return 0;	
				}
				break;
		}
	}
	if(isempty())
		printf("Good");
	else
		printf("Not good");
	return 0;
}
//test data
//([]{[()()]})  good
//()[]{} 		good
//([{}])(		not good
//[(])			not good
//((((((()))))))good
//]()()			not good
