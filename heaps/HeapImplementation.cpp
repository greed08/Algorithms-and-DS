#include<iostream>
#define loop(start,end) for(int i=start;i<=end;i++)
#define loop_r(start) for(int i=start;i>=1;i--)
using namespace std;
template <class Type>
class priority_queue{
	int _size;
	int count;
	int front;
	int rear;
	bool (*comparator)(Type,Type);
	Type *container;
public:
	priority_queue(int,bool (*func)(Type,Type));
	void buildHeap();
	void heapify(int);
	void push(Type);
	Type pop();
	bool isEmpty();
	bool isFull();
	int size();
	void swap(Type &,Type &);
	void print();
};
template <class Type>
void priority_queue<Type>::print(){
	loop(1,_size){
		cout<<container[i]<<", ";
	}
	cout<<"\n";
}
template<class Type>
priority_queue<Type>::priority_queue(int _s,bool(*func)(Type,Type)){
	front=1;
	rear=-1;
	_size=_s;
	comparator=func;
	container=new int[_size+1];
}
template<class Type>
void priority_queue<Type>::buildHeap(){

	loop_r(_size/2){
		heapify(i);
	}
}
template<class Type>
void priority_queue<Type>::swap(Type &a,Type &b){
	Type temp=a;
	a=b;
	b=temp;
}
template<class Type>
void priority_queue<Type>::heapify(int i){
	int left_child=2*i;
	int right_child=left_child+1;
	int new_parent_index=i;
	if(left_child<_size&&comparator(container[new_parent_index],container[left_child]))
	{
		new_parent_index=left_child;
	}
	if(right_child<_size&&comparator(container[new_parent_index],container[right_child]))
	{
		new_parent_index=right_child;
	}
	if(new_parent_index!=i)
	{
		swap(container[i],container[new_parent_index]);
		heapify(new_parent_index);
	}

}
template<class Type>
Type priority_queue<Type>::pop(){
	if(_size==0)
	{
		cout<<"PQ empty"<<"\n";
	}
	else
	{
		Type a=container[1];
		container[1]=container[_size];
		_size=_size-1;
		heapify(1);
		return a;
	}
}
template<class Type>
void priority_queue<Type>::push(Type a){
	if(front>_size)
	{
		cout<<"Queue full"<<"\n";
	}
	container[front++]=a;
	
	


}
template <class Type>
bool comp(const Type a,const Type b)
{
	return a<b;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		priority_queue<int> pq(n,comp);
		for(int i=1;i<=n;i++){
			int val;
			cin>>val;
			pq.push(val);

		}
		pq.buildHeap();
		pq.print();
	}
	return 0;
}
