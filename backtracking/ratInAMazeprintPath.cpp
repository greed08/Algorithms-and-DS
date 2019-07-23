#include<bits/stdc++.h>
#define deb(x) cout<<#x<<":"<<x<<"\n";
#define debug(i,j) cout<<"(i,j)"<<":"<<"("<<i<<","<<")"<<"\n";
int n;
using namespace std;
void solve(int i,int j,vector<vector<int>> maze,int n,string p,vector<string> &paths,vector<vector<bool>> &visited){
	if(i==n-1&&j==n-1)
	{
		visited[i][j]=1;
		paths.push_back(p);
		return;
	}
	if(i<0||j<0||i>n-1||j>n-1||maze[i][j]==0||visited[i][j]==1)
		return;
	visited[i][j]=1;
	solve(i+1,j,maze,n,p+'D',paths,visited);
	solve(i,j+1,maze,n,p+'R',paths,visited);
	solve(i-1,j,maze,n,p+'U',paths,visited);
	solve(i,j-1,maze,n,p+'L',paths,visited);
	visited[i][j]=0;
}
vector<string> printPath(vector<vector<int>> maze,int n)
{
	vector<string> paths;
	string p="";
	vector<vector<bool>> visited(n,vector<bool>(n,0));
	solve(0,0,maze,n,p,paths,visited);
	sort(paths.begin(),paths.end());
	return paths;
}
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		vector<vector<int>> maze(n,vector<int>(n));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>maze[i][j];
			}
		}
		cout<<"Printing paths:"<<"\n";
		for(int i=0;i<n;i++){
			cout<<paths[i]<<",";
		}
		cout<<"\n";
	}

}