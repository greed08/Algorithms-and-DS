#include<bits/stdc++.h>
#define MAX 1000006
using namespace std;
vector<int> G[MAX];
void dfsIterative(int source,vector<bool> &visited){
	stack<int> s;
	s.push(source);
	visited[source]=1;
	
	while(!s.empty()){
		int u=s.top();
		cout<<u<<",";
		s.pop();
		for(auto adj:G[u]){
		if(!visited[adj]){
			s.push(adj);
			visited[adj]=1;
		}
	}
}
}
void dfsRecursive(int source,vector<bool> &visited){
	visited[source]=1;
	for(auto adj:G[source]){
		if(!visited[adj])
			dfsRecursive(adj,visited);
	}
}
int timer=0;
void dfsWithEntryAndExitTime(int source,vector<int> &time_in,vector<int> &time_out, vector<int> &color){
	time_in[source]=timer++;
	color[source]=1;
	for(auto adj:G[source]){
		if(!color[adj])
			dfsWithEntryAndExitTime(adj,time_in,time_out,color);
	}
	color[source]=2;
	time_out[source]=timer++;


}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		int e;
		cin>>n>>e;
		vector<bool> visited(n,false);
		vector<int> time_in(n+1,0);
		vector<int> time_out(n+1,0);
		vector<int> color(n,0);
		for(int i=0;i<e;i++){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		//dfsIterative(1,visited);
		dfsWithEntryAndExitTime(1,time_in,time_out,color);
		for(int i=0;i<=n;i++){
			cout<<i<<" Time out: "<<time_out[i]<<",";
		}
		cout<<"\n";
		for(int i=0;i<=n;i++){
			cout<<i<<" Time out: "<<time_in[i]<<",";
		}
	}
}