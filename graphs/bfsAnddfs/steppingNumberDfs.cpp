#include<bits/stdc++.h>
using namespace std;
vector<int> dfsAndStepping(int low,int high,int n){
	vector<int> solution;
	if(n<=high&&n>=low){
		solution.push_back(n);
	}
	if(n==0||n>high)
	return;
		
	int lastdigit=n%10;

	int step1=n*10+(lastdigit+1);
	int step2=n*10+(lastdigit-1);
	if(lastdigit==0)
		dfsAndStepping(low,high,step1);
	else if(lastdigit==9)
		dfsAndStepping(low,high,step2);
	else{
		dfsAndStepping(low,high,step1);
		dfsAndStepping(low,high,step2);
	}
	return solution;


}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<=9;i++){
			dfsAndStepping(n,m,i);
		}

	}
}