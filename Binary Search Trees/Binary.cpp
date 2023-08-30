#include<iostream>
using namespace std;

struct node{
	int id;
	node *left = NULL;
	node *right = NULL;
};

node *root=NULL;

void insert(){
	node *curr = new node;
	cout<<"Enter id: ";
	cin>>curr->id;
	
	if(root==NULL){
		root=curr;
	}
	else{
		node *p=root;
		node *q=NULL;
		while(p!=NULL){
			
			if(p->id>curr->id){
				q=p;
				p=p->left;
			}
			else if(p->id<curr->id){
				q=p;
				p=p->right;
			}
		}
		if(q->id>curr->id){
			q->left=curr;
		}
		else if(q->id<curr->id){
			q->right=curr;
		}
	}
}

node* Search(int key){
	node *p=root;
	//node *q=NULL;
	
	while(p!=NULL){
		if(key==p->id){
			return p;
		}
		else if(key>p->id){
			//q=p;
			p=p->right;
		}
		else if(key<p->id){
			//q=p;
			p=p->left;
		}
	}
	cout<<"\nKey not found!\n";
	return 0;
}

node* SearchPrev(int key){
	node *p=root;
	node *q=root;
	
	while(p!=NULL){
		if(key==p->id){
			return q;
		}
		else if(key>p->id){
			q=p;
			p=p->right;
		}
		else if(key<p->id){
			q=p;
			p=p->left;
		}
	}
	cout<<"\nKey not found!\n";

}

void del_onebranch(){
	cout<<"Enter id: ";
	int id;
	cin>>id;
	
	
	node *p=Search(id);
	node *q;
	q=SearchPrev(p->id);
		
	
	if(p->left==NULL&&p->right==NULL){
		if(q->left==p){
			q->left=NULL;
		}
		else if(q->right==p){
			q->right=NULL;
		}	
		delete p;
	}
	else if(p->left==NULL||p->right==NULL){
		
		if(q->right==p){
			if(p->right==NULL){
				q->right=p->left;
				delete p;
			}
			else if(p->left==NULL){
				q->right=p->right;
				delete p;
			}
		}
		else if(q->left==p){
			if(p->right==NULL){
				q->left=p->left;
				delete p;
			}
			else if(p->left==NULL){
				q->left=p->right;
				delete p;
				
			}
			}
				
			}
			else{
				node *temp;
				temp = p->right;
				while(temp->left!=NULL){
					temp=temp->left;
				}
				
				node *tempPrev=SearchPrev(temp->id);
				tempPrev->left=NULL;
				
				if(q->left==p){
					q->left=temp;
				}
				else if(q->right==p){
					q->right=temp;
				}
				temp->left=p->left;
				temp->right=p->right;
				delete p;
				
			}
}

int counter=0;		
void countLeafs(node *p){

	if(p!=NULL){
		if(p->left==NULL&&p->right==NULL){
			counter++;
			//cout<<counter<<endl;
		}
		countLeafs(p->left);
		countLeafs(p->right);
	
	}
	
}		
	
		
void preorder(node *p){
	
	if(p!=NULL){
		cout<<p->id<<" ";
		preorder(p->left);
		preorder(p->right);
	}
}

void inorder(node *p){
	if(p!=NULL){
		inorder(p->left);
		cout<<p->id<<" ";
		inorder(p->right);
	}
}

void postorder(node *p){
	if(p!=NULL){
		
		postorder(p->left);
		postorder(p->right);
		cout<<p->id<<" ";
	}
}
void menu(){
	cout<<"\n1-Insert\n2-Display PreOrder\n3-Display Inorder\n4-Display Postorder\n5-Delete\n6-Count Leafs\n7-Exit";
	int choice;
	cout<<"\nChoice: ";
	cin>>choice;
	
	switch(choice){
		case 1:
			insert();
			menu();
			break;
		case 2:
			preorder(root);
			menu();
			break;
		case 3:
			inorder(root);
			menu();
			break;
		case 4:
			postorder(root);
			menu();
			break;
		case 5:
			del_onebranch();
			menu();
			break;
		case 6:
			countLeafs(root);
			cout<<"\nNumber of leafs: "<<counter;
			menu();
			break;
		case 7:
			break;					
		default:
		cout<<"Invalid";
		menu();
		break;		
	}
	
}

int main(){
	menu();
	return 0;
	
}
