#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;
vector<bool> visited(MAX,0);
class Graph
{
private:
	vector<int> G[MAX];
	vector<int> degree;
	int number_vertex=0,number_edges=0;
public:
	Graph(int,int);
	void makeGraph(int,int);
	void dfs(int);
	void rootWhichReturnsMinHeight();
};
Graph::Graph(int n,int e){
	number_vertex=n;
	number_edges=e;
	degree.resize(number_vertex);
	visited.resize(number_vertex,0);

}
void Graph::makeGraph(int u,int v){
	G[u].push_back(v);
	G[v].push_back(u);
	degree[v]++;
	degree[u]++;
}
void Graph::rootWhichReturnsMinHeight(){
	queue<int> q;
	for(int i=0;i<number_vertex;i++){
		if(degree[i]==1)
		q.push(i);
	}


	while(!q.empty()&&number_vertex>2){
		int t=q.front();
		q.pop();
		number_vertex--;
		
		//cout<<number_vertex<<",";
		for(auto j:G[t]){
			degree[j]--;
			if(degree[j]==1)
			{
				//cout<<j<<",";
				q.push(j);
			}
		}
	
}
while(!q.empty()){
	cout<<q.front()<<" ";
	q.pop();
}
	
}
void Graph::dfs(int source){
	visited[source]=1;
	cout<<source<<" ";
	for(auto j:G[source]){
		if(!visited[j]){
			dfs(j);
		}
	}
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int n,e;
		cin>>n;
		
		cin>>e;
		Graph *G1=new Graph(n,e);
		for(int i=0;i<e;i++){
			int u,v;
			cin>>u>>v;
			G1->makeGraph(u,v);
		}
	G1->rootWhichReturnsMinHeight();
	}
}