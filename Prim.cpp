#include<iostream>
#include <fstream>

#define MAX 10   
#define infinte 1000000  

using namespace std;

int martix_max;
int graph_matrix[MAX][MAX];
int used_node[MAX];
int step = 0;
int weight = 0;

void init(int);
void prim_sort();
int find_greed_weight();
int find_greed_node();

int main(){
    ifstream file;
    file.open("test.txt");
    if (file!=NULL){
        file>>martix_max;
        init(martix_max);
        int i = 0, j = 0;
        for (j = 0; j < martix_max;j++){
            for (i = 0; i < martix_max;i++){
                file>>graph_matrix[i][j];
            }
        }
        prim_sort();
    }else{
        cout<<"file does not exist";
        file.close();
    }
    file.close();
}

void init(int max){
    int i = 0, j = 0;
    for (i = 0; i < max;i++){
        for (j = 0; j < max;j++){
            graph_matrix[i][j] = 0;
            used_node[i] = 0;
        }
    }
}

int find_greed_weight(){
    int i = 0;
    int min=infinte;
    //counting having how many nodes are connected
    int j = 0;
    for (j = 0; j < martix_max;j++){
        if (used_node[j] == 1){
            for (i = 0; i < martix_max;i++){
                if (graph_matrix[i][j] < min && graph_matrix[i][j] != 0 && min && graph_matrix[i][j] != -1 && used_node[i]==0){
                    min = graph_matrix[i][j];
                }
            }
        }
    }
    return min;
}

int find_greed_node(){
    int i = 0;
    int min=infinte;
    //counting having how many nodes are connected
    int j = 0;
    int node = -1;
    for (j = 0; j < martix_max;j++){
        if (used_node[j] == 1){
            for (i = 0; i < martix_max;i++){
                if (graph_matrix[i][j] < min && graph_matrix[i][j] != 0 && min && graph_matrix[i][j] != -1 && used_node[i]==0){
                    min = graph_matrix[i][j];
                    node = i;
                }
            }
        }
    }
    return node;
}

void prim_sort(){
    if (step==0){//initial state
        used_node[0] = 1;
        weight += find_greed_weight();
        cout<<"Choose: "<<find_greed_node()+1<<" Weight: "<<weight<<"\n";
        step++;
        if (step!=martix_max){
            prim_sort();
        }
    }else{
        int next_node = find_greed_node();
        used_node[next_node] = 1;
        weight += find_greed_weight();
        cout<<"Choose: "<<find_greed_node()+1<<" Weight: "<<weight<<"\n";
        step++;
        if (step!=martix_max-1){
			prim_sort();
        }
    }
}
