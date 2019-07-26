#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
void printPaths(int** grid,int i,int j,string paths){
    if(i==n-1&&j==m-1){
        paths+=(char)(grid[i][j]+'0');
        cout<<paths<<" ";
        cout<<"\n";
        return;
    }
       
    if(i<0||i>=n||j<0||j>=m)
    return;
    
    printPaths(grid,i+1,j,paths+(char)(grid[i][j]+'0'));
    printPaths(grid,i,j+1,paths+(char)(grid[i][j]+'0'));
    paths=" ";
}
int main(){
    int t;
    cin>>t;
    while(t--){
            cin>>n>>m;
               vector<int> paths;
            int** grid=new int*[n];
            for(int i=0;i<n;i++)
            grid[i]=new int[m];
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cin>>grid[i][j];
                }
            }
    printPaths(grid,0,0," ");
    }
}
