#include<bits/stdc++.h>
using namespace std;
struct Node{
	int val;
	Node *left;
	Node *right;
	Node(int _val):val(_val),left(NULL),right(NULL){}
};
void populateAncestor(Node *root,vector<int> ancestor,vector<vector<int>> &matrix){
	if(root==NULL)
		return;
	ancestor.push_back(root->val);
	for(int i=0;i<ancestor.size();i++){
		if(ancestor[i]==root->val)
			continue;
		else
		matrix[ancestor[i]][root->val]=1;
	}

	populateAncestor(root->left,ancestor,matrix);
	populateAncestor(root->right,ancestor,matrix);
	ancestor.pop_back();


}
int main(){
	int t;
	cin>>t;
	while(t--){
		Node *newNode=new Node(5);
		newNode->left=new Node(1);
		newNode->right=new Node(2);
		newNode->left->left=new Node(0);
		newNode->left->right=new Node (4);
		newNode->right->left=new Node(3);
		vector<vector<int>> matrix(6,vector<int>(6,0));
		vector<int> ancestor;
		populateAncestor(newNode,ancestor,matrix);
		for(int i=0;i<6;i++){
			for(int j=0;j<6;j++){
				cout<<matrix[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
}