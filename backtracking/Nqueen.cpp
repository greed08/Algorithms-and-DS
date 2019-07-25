#include<bits/stdc++.h>
#define deb(x) cout<<#x<< ": "<<x<<"\n";
#define debug(i,j) cout<<"("<<#i<<","<<#j<<")"<<":"<<i<<","<<j<<"\n";
using namespace std;
bool isSafe(vector<vector<int>> board,int i,int j){
	for(int row=0;row<i;row++){
		if(board[row][j]==1)
			return false;
	}
	int x,y;
	x=i;
	y=j;
	while(x>=0&&y>=0){
		if(board[x][y]==1)
			return false;
		x--;
		y--;
	}
	int k,l;
	k=i;
	l=j;
	while(k>=0&&j<board[0].size()){
		if(board[k][l]==1)
			return false;
		i--;
		j++;
	}
	for(int row=board.size()-1;row>=0;row--){
		if(board[row][j]==1)
			return false;
	}

	return true;
}
void printSolution(std::vector<vector<int>> board)
{
	for(int i=0;i<board.size();i++){
		for(int j=0;j<board[0].size();j++){
			cout<<board[i][j]<<" ";
		}
		cout<<"\n";
	}
	
}
void solve(vector<vector<int>> &board,int i,int n){
	if(i==n){
		printSolution(board);
		return;
	}

	for(int row=0;row<n;row++){
		if(isSafe(board,row,i)&& board[row][n]!=1){
			board[row][i]=1;
			solve(board,i+1,n);
			board[row][i]=0;
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<vector<int>> board(n,vector<int>(n,0));
		int start=0;
		solve(board,start,n);
	}
}
