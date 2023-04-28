#include <iostream>
#include <algorithm>

using namespace std;

void quick_sort(int [], int, int);
int partition(int [], int ,int);

int main()
{
	int n=10;//number of keys
	int data[n]={26,5,37,1,61,11,59,15,48,19};
		
	quick_sort(data,0,n-1);
	
	for(int i=0;i<n;i++){
		cout<<data[i]<<" ";
	}
	
}


void quick_sort(int a[], int start, int end)
{
	if(start<end){
		int index=partition(a,start,end);	
		quick_sort(a,start,index-1);
		quick_sort(a,index+1,end);
	}
}

int partition(int a[], int start,int end)
{
	int temp=a[end];
	int i=start-1;
	for (int j=start;j<end;j++){
		if(a[j]<=temp){
			i++;
			swap(a[i],a[j]);
		}
	}
	i++;
	swap(a[i],a[end]);
	return i;
}
