#include<iostream>
using namespace std;

struct BSTnode{
	int val;
	BSTnode *left=NULL;
	BSTnode *right= NULL;
	
};

class BST{
	public:
	BSTnode* root;
	
	public:
	BST(){
		root=NULL;
	}
	
	void insert(int x){
		BSTnode *curr = new BSTnode;
		curr->val=x;
		if(root==NULL){
			root=curr;
		}
		else{
			BSTnode *p=root;
			BSTnode *q=NULL;
			while(p!=NULL){
				if(p->val>x){
					q=p;
					p=p->left;
				}
				else if(p->val<x){
					q=p;
					p=p->right;
				}
			}
			if(q->val>x){
				q->left=curr;
			}
			else if(q->val<x){
				q->right=curr;
			}
		}
	}
	
	void preorder(BSTnode *p){
		
		if(p!=NULL){
			cout<<p->val<<" ";
			preorder(p->left);
			preorder(p->right);	
		}
	}
	
	

};

#define s 7
BST* arr[s];


void hashInsert(int x){
	int index =x%s;	//s = 10;
	arr[index]->insert(x);
}

//void hashDelete(int x){
//	int index= x%s;
//	arr[index]->deletespec(x);
//}

void display(){
	for(int i=0;i<s;i++){
		cout<<i<<": ";
		arr[i]->preorder(arr[i]->root);
		cout<<endl;
	}

}

void menu(){
	cout<<"1-Insert\n2-Display\n3-Exit";
	int choice;
	cout<<"\n\nChoice: ";
	cin>>choice;
	
		switch(choice){
		case 1:
			cout<<"\nEnter value: ";
			int val;
			cin>>val;
			hashInsert(val);
			menu();
			break;
		case 2:
			display();
			menu();
			break;
		case 3:
			break;
			
		default:
		cout<<"\nInvalid\n";
		menu();
		break;				
	}
}
int main(){
	for(int i=0;i<s;i++){
	arr[i]=new BST();
	}
	
	menu();
}
