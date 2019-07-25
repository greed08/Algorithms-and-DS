#include<iostream>
using namespace std;
const static int xMove[8]={-2,-2,-1,-1,1,1,2,2};
const static int yMove[8]={1,-1,-2,2,-2,2,-1,1};
int n;
bool isSafe(int x,int y){
	return (x>=0&&y>=0&&x<n&&y<n);
}
void printSolution(int **solution){
	cout<<"Printing solution"<<"\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<solution[i][j]<<" 	";
		}
		cout<<"\n";
	}
}
	bool solveKnight(int **solution,int i,int j,int count,int &numberOfSolutions){
	if(count==(n*n))
		{
			printSolution(solution);
			return true;
		}
	for(int k=0;k<8;k++){
		int p=i+xMove[k];
		int q=j+yMove[k];
			if(!isSafe(p,q)||solution[p][q]!=-1)
				continue;
			
			solution[p][q]=count;
			if(solveKnight(solution,p,q,count+1,numberOfSolutions)==true)
				return true;
			solution[p][q]=-1;
		

	}
	return false;


}
int main(){
	int t;
	cin>>t;
	while(t--){
	
		cin>>n;
		int** solution=new int*[n];
		for(int i=0;i<n;i++)
			solution[i]=new int[n];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				solution[i][j]=-1;
			}
		}
		int numberOfSolutions=0;
		solution[0][0]=0;
		solveKnight(solution,0,0,1,numberOfSolutions);
			
		cout<<"Total number of solutions"<<": "<<numberOfSolutions;
		for(int i=0;i<n;i++){
			delete[] solution[i];
		}
		delete[] solution;
		
	}
}