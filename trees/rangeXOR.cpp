#include<bits/stdc++.h>
using namespace std;
void buildTree(int *segTree,int *arr,int low,int high,int seg_index){
    if(low==high){
        segTree[seg_index]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    buildTree(segTree,arr,low,mid,seg_index*2+1);
    buildTree(segTree,arr,mid+1,high,seg_index*2+2);
    segTree[seg_index]=segTree[seg_index*2+1]^segTree[seg_index*2+2];
}
int query(int *segTree,int range_min,int range_max,int query_low,int query_high,int seg_index){
    if(query_low<=range_min&&query_high>=range_max)
    return segTree[seg_index];
    if(query_high<range_min||query_low>range_max)
    return 0;
    int mid=(range_min+range_max)/2;
  return  query(segTree,range_min,mid,query_low,query_high,seg_index*2+1)^query(segTree,mid+1,range_max,query_low,query_high,seg_index*2+2);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int *arr=new int[n];
        int *segTree=new int[4*2+1];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        buildTree(segTree,arr,0,n-1,0);
        query()

    }
}
