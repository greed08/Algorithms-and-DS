#include<bits/stdc++.h>
#define  pb push_back
using namespace std;
const static int xMove[8]={-1,-1,-1,0,0,1,1,1};
const static int yMove[8]={-1,0,1,-1,1,-1,0,1};
int n,m;
bool isSafe(int x,int y){
	return (x>=0&&x<n&&y>=0&&y<m);
}
void bfsAndCountRegion(int i,int j,vector<vector<int>> &matrix,int &count,vector<vector<bool>> &visited){
	queue< pair <int,int> > qq;
	qq.push({i,j});
	visited[i][j]=1;
	while(!qq.empty()){
		auto location=qq.front();
		qq.pop();
		for(int i=0;i<8;i++){
			int p=location.first+xMove[i];
			int q=location.second+yMove[i];

			if(isSafe(p,q)){
				if(!visited[p][q]&&matrix[p][q]){
					count++;
					visited[p][q]=1;
					qq.push({p,q});
				}
			}
		}
	}
}
int maxRegionOfOnes(vector<vector<int>> &matrix,vector<vector<bool>> &visited){
	int max_region=INT_MIN;
	
	for(int i=0;i<matrix.size();i++){
		for(int  j=0;j<matrix[i].size();j++){
			if(!visited[i][j]&&matrix[i][j]==1){
				int count=1;
				bfsAndCountRegion(i,j,matrix,count,visited);
				
				max_region=max(max_region,count);
			}
		}
	}
	return max_region;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		
		cin>>n>>m;
		vector<vector<int>> matrix(n,vector<int> (m,0));
		vector<vector<bool>> visited(n,vector<bool> (m,0));
		for(int i=0;i<n;i++){
			matrix.pb(vector<int>());
			for(int j=0;j<m;j++){
				cin>>matrix[i][j];
			}
		}
		cout<<maxRegionOfOnes(matrix,visited);
		
	}
}