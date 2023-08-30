#include<iostream>
using namespace std;

struct node{
	int value;
	node *next=NULL;
};
node *f=NULL;
node *l= NULL;

void insert_end(int x){
	node *curr= new node;
	curr->value=x;
	
	if(f==NULL){
		f=l=curr;
	}
	else{
		l->next=curr;
		l=curr;
	}
}

void linearSearch(int key){
	node *p=f;
	while(p!=NULL){
		if(p->value==key){
			cout<<"Found\n";
			return;
		}
		p=p->next;
	}
	cout<<"Not found\n";
}

node* findMid(node *first,node *last){
	node *p=first;
	node *q=first;
	
	while(q!=last&& q->next!=last){
		p=p->next;
		q=q->next->next;
	}
	return p;
}



void binarySearch(node *first, node *last,int key){
	if(first==NULL||last==NULL){
		cout<<"Not found";
	}
	
	node *mid = findMid(first,last);
	
	if(mid->value==key){
		cout<<"Found\n";

	}
	else if(mid->value > key){
		
		binarySearch(first,mid,key);
	}
	else if(mid->value<key){
		binarySearch(mid->next,last,key);
	}
}

int main(){
	for(int i=0;i<20;i++){
		insert_end(i+1);
	}
	
	linearSearch(15);
	binarySearch(f,l,18);
}
