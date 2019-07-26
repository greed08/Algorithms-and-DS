#include<iostream>
#define QUEEN 1
using namespace std;
int n_queen;
int board_size;
void printSolution(int **chess_board){
	cout<<"Printing solution"<<"\n";
	for(int i=0;i<board_size;i++){
		for(int j=0;j<board_size;j++){
			if(chess_board[i][j]==1)
                cout<<"Q"<<" ";
            else
                cout<<"-"<<" ";
		}
		cout<<"\n";
	}
}
bool isSafe(int row,int col,int **chess_board){
int i,j;
   
    for( i=0;i<board_size;i++)
      if(chess_board[i][col]==1)
        return false;

    for(int i=0;i<board_size;i++)
        if(chess_board[row][i]==1)
            return false;
  
    i=row-1;
    j=col+1;
    while(i>=0&&j<board_size)
    {
        if(chess_board[i][j]==1)
            return false;
        i--;
        j++;
    }
    i=row-1;
    j=col-1;
    while(i>=0&&j>=0)
    {
        if(chess_board[i][j]==1)
            return false;
        i--;
        j--;
    }
    return true;
}
void solveNQueen(int **chess_board,int i,int n_queen){
	 if(i>=n_queen)
    {
        printSolution(chess_board);
        return ;
    }

    for(int col=0;col<board_size;col++)
    {
        if(isSafe(i,col,chess_board))
        {
            chess_board[i][col]=1;

          solveNQueen(chess_board,i+1,n_queen);
           

            chess_board[i][col]=0;
        }
    }
return;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		
		cin>>n_queen;
		cin>>board_size;
		int** chess_board=new int*[board_size];
		for(int i=0;i<board_size;i++){
			chess_board[i]=new int[board_size];
		}
		for(int i=0;i<board_size;i++){
			for(int j=0;j<board_size;j++)
				chess_board[i][j]=0;
		}
		
		solveNQueen(chess_board,0,n_queen);


	}
}