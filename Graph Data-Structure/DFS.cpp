#include<iostream>
#include<list>
using namespace std;

const int v =8;
list<int> stack;
bool visited[v];
int graph[v][v]={
	{0,1,1,1,0,0,0,0},
	{1,0,0,1,0,0,0,0},
	{1,0,0,0,1,1,0,0},
	{1,1,0,0,0,1,1,0},
	{0,0,1,0,0,1,0,1},
	{0,0,1,1,1,0,0,0},
	{0,0,0,1,0,0,0,0},
	{0,0,0,0,1,0,0,0}
};

void DFS(int start){
	visited[start]=true;
	stack.push_back(start);
	
	while(!stack.empty()){
		start = stack.back();
		cout<<start<<" ";
		stack.pop_back();
		
		for(int i=0;i<v;i++){
			if(graph[start][i]==1&&!visited[i]){
				visited[i]=true;
				stack.push_back(i);
				
			}
		}
		
	}
}

int main(){
	DFS(0);
}
