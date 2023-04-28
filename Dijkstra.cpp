#include<iostream>
#include <fstream>

#define MAX 10   
#define infinte 1000000  

using namespace std;


int minimumDist(int*, bool, int); 
void Dijkstra(int);
void init(int);


int martix_max;
int graph_matrix[MAX][MAX];

int main(){
    ifstream file;
    file.open("test.txt");
    if(file!=NULL){
        int martix_max = 0;
        file>>martix_max;
        init(martix_max);
        int i = 0, j = 0;
        for (i = 0; i < martix_max;i++){
            for (j = 0; j <martix_max;j++){
                int a;
                file>>a;
                if (a==-1){
                    graph_matrix[i][j] = infinte;
                }else{
                    graph_matrix[i][j] = a;
                }
            }
        }
        
        Dijkstra(martix_max);

    }else{
        cout<<"file do not exist";
        file.close();
    }
    file.close();
}

void init(int max){
    int i = 0, j = 0;
    for (i = 0; i < max;i++){
        for (j = 0; j < max;j++){
            graph_matrix[i][j] = 0;
        }
    }
}

// vertex which is not included in Tset.
int minimumDist(int dist[], bool used[], int max) 
{
	int min=infinte,index;
              
	for(int i=0;i<max;i++) 
	{
		if(used[i]==false && dist[i]<=min)      
		{
			min=dist[i];
			index=i;
		}
	}
	return index;
}

void Dijkstra(int max) // adjacency matrix used is 6x6
{
	int dist[max]; // integer array to calculate minimum distance for each node.                            
	bool used[max];// boolean array to mark visted/unvisted for each node.
	
	// set the nodes with infinity distance
	// except for the initial node and mark
	// them unvisited.  
	for(int i = 0; i<max; i++)
	{
		dist[i] = infinte;
		used[i] = false;	
	}
	
	dist[0] = 0;   // Source vertex distance is set to zero.             
	
	for(int i = 0; i<max; i++)                           
	{
		int m=minimumDist(dist,used,max); // vertex not yet included.
		
		used[m]=true;// m with minimum distance included in used
		for(int i = 0; i<max; i++)                  
		{
			// Updating the minimum distance for the particular node.
			if(!used[i] && graph_matrix[m][i]>0 && dist[m]!=infinte && dist[m]+graph_matrix[m][i]<dist[i]){

				dist[i]=dist[m]+graph_matrix[m][i];
			}
		}
	}


	for(int i = 1; i<max; i++)                      
	{ //Printing
		cout<<"from 1 to "<<i+1<<"      Shortest Distance = "<<dist[i]<<" \n";
	}
}



