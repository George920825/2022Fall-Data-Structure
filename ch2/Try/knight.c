#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 8
clock_t start, end;
double sum = 0;

int solveKT();
int solveKTUtil(int x, int y, int stepNum, int sol[N][N], int xMove[], int yMove[]);
int isSafe(int x, int y, int sol[N][N]);
void printSolution(int sol[N][N]);

int main()
{
    solveKT();
    return 0;
}

int solveKT()
{
    int xMove[8]={2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[8]={1, 2, 2, 1, -1, -2, -2, -1};

    int sol[N][N];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            sol[i][j] = -1;
    sol[0][3] = 0;

    if(solveKTUtil(0, 3, 1, sol, xMove, yMove) == 0)
    {
        printf("Solution does not exist.");
        return 0;
    }
    else
        printSolution(sol);
    return 1;
}

int solveKTUtil(int x, int y, int stepNum, int sol[N][N], int* xMove, int* yMove)
{
    int k, xNext, yNext;
    start = clock();
    if(stepNum == N*N)
        return 1;
    for(k = 0; k < 8; k++)
    {
        xNext = x + xMove[k];
        yNext = y + yMove[k];
        
        if(isSafe(xNext, yNext, sol))
        {
            sol[xNext][yNext] = stepNum;
            
            if(solveKTUtil(xNext, yNext, stepNum+1, sol, xMove, yMove) == 1)
            {
                end = clock();
                double time = end - start;
                sum = sum + time;
                printf("%lf\n", sum / CLOCKS_PER_SEC);
                return 1;
            }
            else
                sol[xNext][yNext] = -1;
        }
    }
    return 0;
}

int isSafe(int x, int y, int sol[N][N])
{
    return(x >= 0 && x < N && y >=0 && y < N && sol[x][y] == -1);
}

void printSolution(int sol[N][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            printf("%3d",sol[i][j]);
        printf("\n");
    }
}