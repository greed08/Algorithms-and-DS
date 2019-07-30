#include<bits/stdc++.h>

using namespace std;
int n;
set<int> ss;
int  checkModulus(string s){
	int rem=0;
	for(int i=0;i<s.size();i++){
		rem=(rem*10+s[i]-'0')%n;
	}
	return rem;
}
string solve(string s){

	queue<string> q;
	q.push("1");
	while(!q.empty()){
		string t=q.front();
		q.pop();
		int rem=checkModulus(t);
		if(rem==0)
			return t;
		else if(ss.find(checkModulus(t))==ss.end())
		{
			ss.insert(rem);
			q.push(t+"1");
			q.push(t+"0");
		}
	}
	return "Hellow";
	
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<solve("1");	
	}
}