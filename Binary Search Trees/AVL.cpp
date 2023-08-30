#include<iostream>
using namespace std;

struct node{
	int id;
	node *left=NULL;
	node *right=NULL;
};

node *root = NULL;

int height(node *p){  
	if(p==NULL){
		return 0;
	}
	else{
		int l= height(p->left);
		int r= height(p->right);
		int h = 1 + max(l,r);
		return h;
	}
}

int balanceFactor(node *p){ //balance factor of each node  
	if(p==NULL){
		return 0;
	}
	else
	{
		return(height(p->left)-height(p->right));
	}
}

node* Search(int key){
	node *p=root;
	while(p!=NULL){
		if(key==p->id){
			return p;
		}
		else if(key>p->id){
			
			p=p->right;
		}
		else if(key<p->id){
		
			p=p->left;
		}
	}
	cout<<"\nKey not found!\n";
	return 0;
}


node* searchPrev(int key){
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

void left_left(node *r){
	node *r_prev = searchPrev(r->id);
	
	node *p=r->right;
	
	r->right=p->left;
	p->left=r;
	
	if(r_prev->left==r){
		r_prev->left=p;
	}
	else if(r_prev->right==r){
		r_prev->right=p;
	}
	
	if(r==root){
		root=p;
	}
}

void right_right(node *r){
	node *r_prev=searchPrev(r->id);
	node *p=r->left;
	
	r->left=p->right;
	p->right=r;
	
	if(r_prev->left==r){
		r_prev->left=p;
	}
	else if(r_prev->right==r){
		r_prev->right=p;
	}
	if(r==root){
		root=p;
	}
}

void left_right(node *r){   
	node *p=r->left;
	
	left_left(p);
	right_right(r);

}

void right_left(node *r){  
	node *p=r->right;
	
	right_right(p);
	left_left(r); 
	
}

void AVL_Balancing(node *r){
	if(r!=NULL){
		AVL_Balancing(r->left);
		AVL_Balancing(r->right);
	if(balanceFactor(r) > 1){
		if(r->left != NULL && height(r->left->left) > height(r->left->right))
			right_right(r);
		else if(r->left != NULL && height(r->left->left) < height(r->left->right))
			left_right(r);
}
	else if(balanceFactor(r) < -1){
		if(r->right != NULL && height(r->right->right) > height(r->right->left))
                left_left(r);
        else if(r->right != NULL && height(r->right->right) < height(r->right->left))
                right_left(r);
}
	}
}

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
	
	//AVL_Balancing(root);
	
}

void delete_node(){
	cout<<"Enter id: ";
	int id;
	cin>>id;
	
	
	node *p=Search(id);
	node *q;
	q=searchPrev(p->id);
		
	
	if(p->left==NULL&&p->right==NULL){  //leaf
		if(q->left==p){
			q->left=NULL;
		}
		else if(q->right==p){
			q->right=NULL;
		}	
		delete p;
	}
	else if(p->left==NULL||p->right==NULL){  //one branch
		
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
else{  //two branch
	node *t = p->right;
	node *t1=NULL;
	if(t->left==NULL){
		p->id=t->id;
		p->right=NULL;
		delete t;
	}
	else{
	
	while(t->left!=NULL){
		t1=t;
		t=t->left;
	}
	p->id=t->id;
	t1->left=NULL;
	delete t;
	}			
			}
AVL_Balancing(root);
			
}

void preorder(node *p){
	
	if(p!=NULL){
		cout<<p->id<<"("<<balanceFactor(p)<<")"<<" ";
		preorder(p->left);
		preorder(p->right);
	}
}

void inorder(node *p){
	if(p!=NULL){
		inorder(p->left);
		cout<<p->id<<"("<<balanceFactor(p)<<")"<<" ";
		inorder(p->right);
	}
}

void postorder(node *p){
	if(p!=NULL){
		
		postorder(p->left);
		postorder(p->right);
		cout<<p->id<<"("<<balanceFactor(p)<<")"<<" ";
	}
}

void menu(){
	cout<<"\n1-Insert BST\n2-Insert & Balance\n3-Balance Tree\n4-Display\n5-Delete\n6-Exit\n";
	int choice;
	cout<<"\nYour Choice: ";
	cin>>choice;
	
	switch(choice){
		case 1:
			insert();
			menu();
			break;
		case 2:
			insert();
			AVL_Balancing(root);
			menu();
			break;
		case 3:
			AVL_Balancing(root);
			menu();
			break;
		case 4:
			cout<<"\nPreOrder: ";
			preorder(root);
			cout<<"\nInOrder: ";
			inorder(root);
			cout<<"\nPostOrder: ";
			postorder(root);
			cout<<endl;
			menu();
			break;
		case 5:
			delete_node();
			menu();
			break;
		case 6:
			break;			
		default:
		cout<<"\nInvalid Choice\n";
		menu();
		break;			
	}
}

int main(){
	menu();
}

