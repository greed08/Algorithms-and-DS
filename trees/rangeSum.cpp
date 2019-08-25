#include<bits/stdc++.h>
using namespace std;
void buildTree(int *segTree,int *arr,int seg_index,int low,int high){
    if(low==high){
        segTree[seg_index]=arr[low];
        return;
    }
    int mid=low+(high-low)/2;
    buildTree(segTree,arr,seg_index*2+1,low,mid);
    buildTree(segTree,arr,seg_index*2+2,mid+1,high);
    segTree[seg_index]=segTree[seg_index*2+1]+segTree[seg_index*2+2];
}
int query(int *segTree,int range_min,int range_max,int query_low,int query_high,int seg_index){
    if(query_low<=range_min&&query_high>=range_max)
    return segTree[seg_index];
    if(query_high<range_min||query_low>range_max)
    return 0;
    int mid=(range_min+range_max)/2;
    return query(segTree,range_min,mid,query_low,query_high,seg_index*2+1)+query(segTree,mid+1,range_max,query_low,query_high,seg_index*2+2);
}
void update(int *segTree,int range_min,int range_max,int seg_index,int pos,int new_val){
    if(range_min==range_max){
        segTree[seg_index]=new_val;
        return;
    }
    int mid=(range_min+range_max)/2;
    if(pos<=mid)
        update(segTree,range_min,mid,seg_index*2+1,pos,new_val);
    else
        update(segTree,mid+1,range_max,seg_index*2+2,pos,new_val);
    segTree[seg_index]=segTree[seg_index*2+1]+segTree[seg_index*2+2];
    

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int *arr=new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int* segTree=new int [4*n+1];
        buildTree(segTree,arr,0,0,n-1);
        cout<<"Print segment tree"<<"\n";
        for(int i=0;i<=2*n;i++){
            cout<<segTree[i]<<" ";
        }
        cout<<"\n";
        cout<<"Query result: "<<"\n";
        cout<<query(segTree,0,n-1,0,2,0)<<"\n";
        cout<<"Update:"<<"\n";
        update(segTree,0,n-1,0,1,5);
        cout<<"Query after update"<<"\n";
        cout<<query(segTree,0,n-1,1,2,0)<<"\n";
         for(int i=0;i<=2*n;i++){
            cout<<segTree[i]<<" ";
        }
    }
}
