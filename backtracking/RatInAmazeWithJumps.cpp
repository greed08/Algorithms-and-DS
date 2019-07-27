#include<iostream>
#include<vector>
using namespace std;
int maze_size;
void printSolution(vector<vector<int>> &solution){
    cout<<"Printing solution for rat in a maze"<<"\n";
    for(int i=0;i<maze_size;i++){
        for(int j=0;j<maze_size;j++){
            cout<<solution[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void solveRatInAMaze(int **maze,int i,int j,vector<vector<int>> &solution){
    if(i==maze_size-1&&j==maze_size-1)
    {
    solution[i][j]=1;
    printSolution(solution);
    return;
    }
    if(i<0||j<0||i>maze_size-1||j>maze_size-1||solution[i][j]==1)
    return;
    
    solution[i][j]=1;
    for(int k=1;k<=maze[i][j];k++){
        solveRatInAMaze(maze,i+k,j,solution);
        solveRatInAMaze(maze,i,j+k,solution);
    }
    solution[i][j]=0;

return;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>maze_size;
        int** maze=new int*[maze_size];
        for(int i=0;i<maze_size;i++)
        maze[i]=new int[maze_size];
        for(int i=0;i<maze_size;i++){
            for(int j=0;j<maze_size;j++){
                cin>>maze[i][j];
            }
        }
        vector<vector<int>> solution(maze_size,vector<int>(maze_size,0));
        solveRatInAMaze(maze,0,0,solution);

        for(int i=0;i<maze_size;i++)
            delete[] maze[i];
        delete[] maze;
    }
}
