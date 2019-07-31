#include<bits/stdc++.h>
using namespace std;
vector<int> G[100000];
vector<int> color;
void detectCycle(int src,stack<int> cycle){
	color[src]=1;
	
	cycle.push(src);
	for(auto adj:G[src]){
		if(!color[adj]){
			
			detectCycle(adj,cycle);
		}
		else
		{
			cycle.push(adj);
			cout<<"Printing cycle now :"<<"\n";
			while(!cycle.empty()){
				cout<<cycle.top()<<"-->";
				cycle.pop();
			}
			cout<<"\n";
		}
		
		
		
	}


	color[src]=2;

}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,e;
		cin>>n>>e;
		for(int i=0;i<e;i++){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);

		}
		color.resize(n,0);
		stack<int> cycle;
		for(int i=0;i<n;i++){
			if(!color[i])
			detectCycle(i,cycle);
		}

	}
}