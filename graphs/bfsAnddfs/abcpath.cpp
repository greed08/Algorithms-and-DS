#include<bits/stdc++.h>
using namespace std;
int h,w;
const static int xMove[8]={-1,-1,-1,0,0,1,1,1};
const static int yMove[8]={-1,0,1,-1,1,-1,0,1};
int solve(int i,int j,vector<vector<char>> matrix,vector<vector<int>> &solution){
	if(solution[i][j]!=-1) return solution[i][j];
	int ans=0;
	for(int k=0;k<8;k++){
		int p=i+xMove[k];
		int q=j+yMove[k];
		if(p>=0&&p<h&&q>=0&&q<w){
		if(matrix[p][q]==(char)(1+matrix[i][j])){
			ans=max(ans,solve(p,q,matrix,solution));
		}
	}
}
return solution[i][j]=1+ans;
}


int main(){
	while(1){
		cin>>h>>w;
		int testCase=0;
		if(h==0&&w==0)
			break;
		else
		{
			testCase++;
			vector<vector<char>> matrix(h,vector<char>(w));
			vector<vector<int>> solution(h,vector<int>(w,-1));
			for(int i=0;i<h;i++){
				for(int j=0;j<w;j++){
					cin>>matrix[i][j];
				}

			}
			int ans=0;
			for(int i=0;i<h;i++){
				for(int j=0;j<w;j++){
					if(matrix[i][j]=='A'){
						ans=max(ans,solve(i,j,matrix,solution));
					}
				}
			}
			
			cout<<"Case "<<testCase<<":"<<" "<<ans<<"\n";
		}
	}
}