#include<iostream>
#include<string>
#include<sstream>
using namespace std;

#define v 4

int graph[v][v]= { 		{ 0, 4, 0, 7},
                        { 4, 0, 8, 0},
                    	{ 0, 8, 0, 1},
                        { 7, 0, 1, 0},
                        
    };
    
bool visited[v];
int dist[v];
string path[v];


int findMin(int arr[]){
	int min=INT_MAX;
	int min_index=0;
	
	for(int i=0;i<v;i++){
	if(!visited[i]&&arr[i]<=min){
			min=arr[i];
			min_index = i;
	}
	}
	return min_index;
}

void display(){
	cout<< "Vertex \t\t Distance  \tPath\n";
	for (int i = 0; i < v; i++)
        cout<< i << " \t\t "<<dist[i]<<"\t\t "<<path[i]<<"\n";
}

void dijkstra(int src){

	dist[src]=0;
	
	for(int i=0;i<v;i++){
		
		int min = findMin(dist);
		visited[min]=true;
		
		for(int j=0;j<v;j++){
			if(!visited[j]&& graph[min][j]&& dist[min]!=INT_MAX && (dist[min]+graph[min][j]<dist[j])){
			
				dist[j]= dist[min]+graph[min][j];
				
				path[j]=path[min];
				stringstream stream; 
				string s;
				stream<<j;
				stream>>s;
				path[j]=path[j].append("->").append(s);
			}
		}
	}
	display();
}



int main(){
	int src =0;
	stringstream stream; string s;
	stream<<src;
	stream>>s;
	
	for(int i=0;i<v;i++){	
	path[i] = s;
	visited[i]=false;
	dist[i]=INT_MAX;
	}
	
	dijkstra(src);
	
}

