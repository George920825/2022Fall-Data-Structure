#include <iostream>
#include <algorithm>
#define n 10
using namespace std;

int a[n]={45,83,7,61,12,99,44,77,14,29};

void heaplify(int x,int max);

int main()
{
	cout<<"original array : ";
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
	

//	create heap tree 
	for(int i=(n-1)/2;i>=0;i--){
		heaplify(i,n-1);
	}
	cout<<"heap tree : ";	
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
	
//	heap sort
	for(int i=0;i<n-3;i++){
		swap(a[0],a[n-1-i]);
		heaplify(0,n-1-i);
		for(int j=0;j<n;j++)
			cout<<a[j]<<" ";
		cout<<"\n";
	}
		
	if(a[1]<a[2])
		swap(a[1],a[2]);
	swap(a[0],a[2]);
	
	cout<<"sorted array : ";
	for(int i=0;i<n;i++)
		cout<<a[i]<<" "; 
}

void heaplify(int x,int max){
	int index=2*x+1;
	if(a[index]<a[index+1])
		index+=1;
	
	if(a[x]<a[index]){
		swap(a[x],a[index]);
		if(2*(index+1)<max){
			heaplify(index,max);
		}
	}
}
