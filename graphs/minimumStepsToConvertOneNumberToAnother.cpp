#include<bits/stdc++.h>
using namespace std;
void solve(int n1,int n2){
	queue<int> q;
	if(n1!=n2)
		q.push(n1);
	int steps=0;
	set<int> s;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		if(t==n2)
		{
			cout<<steps<<"";
		}
		else
		{
			if(t*2==n2||t-1==n2)
			{
				cout<<steps+1<<"\n";
			}
			
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n1,n2;
		cin>>n1>>n2;
		solve(n1,n2);
	}
}