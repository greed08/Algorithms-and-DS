#include<bits/stdc++.h>
using namespace std;
vector<int> G[1000000];
vector<int> time_in;
vector<int> time_out;
vector<bool> visited;
int timer=0;
void dfsUtil(int source){
	time_in[source]=timer++;
	visited[source]=1;
	for(auto j:G[source]){
		if(!visited[j]){
			dfsUtil(j);
			visited[j]=1;
		}
	}
	time_out[source]=timer++;


}
bool isBothLieInSamePath(int a,int b){
	return ((time_in[a]<time_in[b]&&time_out[a]>time_out[b])||(time_in[b]<time_in[a]&&time_out[b]>time_out[a]));
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,e;
		cin>>n>>e;
		time_in.resize(n,0);
		time_out.resize(n,0);
		visited.resize(n,0);
		for(int i=0;i<e;i++){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfsUtil(1);

		cout<<isBothLieInSamePath(2,5)<<"\n";
		cout<<isBothLieInSamePath(2,3)<<"\n";


	}
}