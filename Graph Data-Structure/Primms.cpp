#include<iostream>
using namespace std;

#define v 5
int graph[v][v] = { 	{ 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
    
bool visited[v];
int parent[v];
int dist[v];

int findMin(int arr[]){
	int min = INT_MAX, min_index;
 
    for (int i = 0; i < v; i++){
	
        if (!visited[i] && dist[i] < min){
		
            min = dist[i]; 
			min_index = i;
		}
}
    return min_index;
}

void display(){
	cout<<"Path \tCost\n";
	for (int i = 1; i < v; i++)
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
}

void primms(int src){
	dist[src]=0;
	parent[src]=0;
	
	for(int i=0;i<v;i++){
		int min = findMin(dist);
		visited[min]=true;
		for(int j=0;j<v;j++){
			if(graph[min][j]!=0 && !visited[j] &&graph[min][j]<dist[j]){
				dist[j]=graph[min][j];
				parent[j]=min;
			}
		}
	}
	display();
}

int main(){
	int src = 0;
	
	for (int i = 0; i < v; i++){
	
        dist[i] = INT_MAX;
		visited[i] = false;
	}
	
	primms(src);
}
