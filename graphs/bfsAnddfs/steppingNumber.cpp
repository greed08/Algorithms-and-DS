#include<bits/stdc++.h>
using namespace std;
void bfsAndFindSteppingNumber(int i,int n,int m){
	queue<int> q;
	q.push(i);
	int step1;
	int step2;
	while(!q.empty()){
		int number=q.front();
		if(number>=n||number<=m)
			cout<<number<<",";
		q.pop();
		int last_digit=number%10;
		if(i>m||number==0)
			continue;
		step1=number*10+(last_digit+1);
		step2=number*10+(last_digit-1);
		if(last_digit==0)
			q.push(step1);
		if(last_digit==9)
			q.push(step2);
		else
		{
			q.push(step1);
			q.push(step2);
		}

	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<=9;i++)
			bfsAndFindSteppingNumber(i,n,m);
	}
}