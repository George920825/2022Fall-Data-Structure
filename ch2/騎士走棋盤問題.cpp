#include<iostream>
using namespace std;

void solveKT();
int solveKTUtil(int, int, int, int sol[8][8], int xM[8], int yM[8]);
bool isSafe(int, int, int[8][8]);
void printSolution(int sol[8][8]);

int main(){
	solveKT();
	
	return 0;
}

void solveKT(){
	int sol[8][8];
	
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			sol[i][j] = -1;
		}
	}
	
	int xMove[8]={2, 2, 1, -1, -2, -2, -1, 1};
	int yMove[8]={1, -1, -2, -2, -1, 1, 2, 2};
	
	int xStart=0, yStart=0;
	sol[xStart][yStart] = 0;
	
	if(solveKTUtil(xStart, yStart, 1, sol, xMove, yMove) == 0){
		cout << "No solution" <<endl;
	}else{
		printSolution(sol);
	}
}

int solveKTUtil(int x, int y, int step, int sol[8][8], int xM[8], int yM[8]){
	int next_x, next_y, k;
	if(step == 64){
		return 1;
	}
	do{
		next_x = x + xM[k];
		next_y = y + yM[k];
		if(isSafe(next_x, next_y, sol)){
			sol[next_x][next_y] = step;
			//cout << "x:" << next_x << " y:" << next_y << " step:" << step <<endl;
			if(solveKTUtil(next_x, next_y, step+1, sol, xM, yM) == 0){
				//k++;
				sol[next_x][next_y] = -1;
			}
			else{
				return 1;
			}
		}
		/*else{
			k++;
		}*/
		k++;
	}while(k < 8);
	
	return 0;
}

bool isSafe(int x, int y, int sol[8][8]){
	return (x>=0 && x<8 && y>=0 && y<8 && sol[x][y]==-1);
}

/*void printSolution(int sol[8][8]){
	cout << "\n\n";
	for(int i=0;i<64;i++){
		int j=0, k=0;
		do{
			if(sol[j][k] == i){
				cout << "��" << i << "�B:[" << j << "][" << k << "]\n";
				break;
			}
			if(++k=8){
				k = 0;
				j++;
			}		
		}while(j<8); 
	}
}*/

void printSolution(int sol[8][8])
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
            printf("%3d",sol[i][j]);
        printf("\n");
    }
}
