#include<iostream>
#include<list>
using namespace std;

const int v = 5;
list<int> queue;
bool visited[v];     
int graph[v][v]={  {0,1,1,1,0},
				   {1,0,1,0,0},
				   {1,1,0,0,1},
				   {1,0,0,0,0},
				   {0,0,1,0,0}}; 

//void addEdge(int x,int y){
//	graph[x][y]=1;
//	graph[y][x]=1;
//}
    
void BFS(int start){
	visited[start]=true;
	queue.push_back(start);
	
	while(!queue.empty()){
		start = queue.front();
		cout<<start<<" ";
		queue.pop_front();
		
		for(int i=0;i<v;i++){
			if(graph[start][i]==1 && visited[i]==false){
				visited[i]=true;
				queue.push_back(i);
			}
		}
		
	}
}


int main(){
	BFS(0);
}


