#include<bits/stdc++.h>
using namespace std;
vector<int> G[100000];
int minimumSumofComponenent(int src,vector<int> nodeValue,vector<bool> &visited){
	visited[src]=1;
	int min_value=nodeValue[src-1];
	for(auto adj:G[src]){
		if(!visited[adj]){
			
			//cout<<min_value<<"--"<<"\n";
			minimumSumofComponenent(adj,nodeValue,visited);
			min_value=min(min_value,nodeValue[adj-1]);
			visited[adj]=1;
		}
	}
	return min_value;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,e;
		cin>>n>>e;
		vector<int> nodeValue(n);
		for(int i=0;i<n;i++){
			cin>>nodeValue[i];
		}
		for(int i=0;i<e;i++){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);

		}
		int ans=0;
		vector<bool> visited(n+1,0);
		for(int i=1;i<=n;i++){
			if(!visited[i]){
				ans+=minimumSumofComponenent(i,nodeValue,visited);
			}
		}
		cout<<ans<<"\n";
	}
}