#include<bits/stdc++.h>
#define MAX 1000006
using namespace std;
vector<int> G[MAX];
void bfs(int source,vector<bool> &visited){
	queue<int> q;
	q.push(source);
	visited[source]=1;
	while(!q.empty()){
		int v=q.front();
		q.pop();
		cout<<v<<",";
		for(auto u:G[v]){
			if(!visited[u]){
				q.push(u);
				visited[u]=1;
			}
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,e;
		cin>>n>>e;
		vector<bool> visited(n,false);
		for(int i=0;i<e;i++){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		bfs(1,visited);
	}
}