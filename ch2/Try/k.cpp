#include<iostream>
using namespace std;
#define N 6

int checkerboard[N][N]={0};

int xMove[8]={2,1,-1,-2,-2,-1,1,2};
int yMove[8]={1,2,2,1,-1,-2,-2,-1};

int step=0;
bool findanswer=false;

void printarray(int a[N][N]){
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<a[i][j]<<"\t";
		}
		
		cout<<"\n\n";
	}
	return;
}

void knight(int x,int y){
	step++;
	checkerboard[x][y]=step;
	if(step==N*N)
	{
		printarray(checkerboard);
		findanswer=true;
	}
	
	int newx,newy;
	for(int i=0;i<8;i++)
	{
		newx=x+xMove[i];
		newy=y+yMove[i];
		
		if(newx>=N||newx<0)
		{
			continue;
		}
		if(newy>=N||newy<0)
		{
			continue;
		}
		
		if(checkerboard[newx][newy]==0)
		{
			knight(newx,newy);
			
			if(findanswer==true)
			{
				return;
			}
		}
	}
}


int main(){
	
	knight(0,0);
	
} 
