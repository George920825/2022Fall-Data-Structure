#include <iostream>

using namespace std;

int main()
{
	int n=10,temp;
	int array[n]={5,2,4,12,8,6,9,7,11,10};
	
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<i;j++){
			if(array[j]>array[j+1]){
				temp=array[j+1];
				array[j+1]=array[j];
				array[j]=temp;
			}
		}
		cout<<n-i<<" sorting :";
		for(int j=0;j<n;j++){
			cout<<array[j]<<" ";
		}	
		cout<<"\n";
	}
	
}

