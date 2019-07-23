#include<bits/stdc++.h>
#define deb(x) cout<<#x<< ": "<<x<<"\n";
#define debug(i,j) cout<<"("<<#i<<","<<#j<<")"<<":"<<i<<","<<j<<"\n";
using namespace std;
int N;
void printSolution(vector<vector<int>> solution){
	cout<<"Printing solution"<<"\n";
	for(int i=0;i<solution.size();i++){
		for(int j=0;j<solution[0].size();j++){
			cout<<solution[i][j]<<" ";
		}
		cout<<"\n";
	}
	/*for(int i=0;i<path.size();i++){
		cout<<path[i]<<" ";
	}*/
}
void solve(int i,int j,vector<vector<int>> matrix,vector<vector<int>> &solution){

	if(i==N-1&&j==N-1){
		solution[i][j]=1;
		printSolution(solution);
		return;
	}
	if(i<0||i>N-1||j<0||j>N-1||matrix[i][j]==0||solution[i][j]==1)
		return;
	solution[i][j]=1;
	solve(i+1,j,matrix,solution);
	solve(i,j+1,matrix,solution);
	solve(i-1,j,matrix,solution);
	solve(i,j-1,matrix,solution);
	solution[i][j]=0;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		
		cin>>N;
		vector<vector<int>> matrix(N,vector<int>(N,0));
		vector<vector<int>> solution(N,vector<int>(N,0));
		vector<char> path;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cin>>matrix[i][j];
			}
		}
		solve(0,0,matrix,solution);
		for(int i=0;i<path.size();i++){
			cout<<path[i]<<" ";
		}
	}
}