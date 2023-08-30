#include<iostream>
#include<string>
using namespace std;

struct stack{
	string str;
	stack *next;
};

stack *top=NULL;
stack *first=NULL;

bool isEmpty(){
	return first==NULL;
}

void push(stack *s){
	if(first==NULL){
		first=top=s;
	}
	else{
		top->next = s;
		top=s;
	}
	
}

void pop(){
	if(first==NULL){
		cout<<"\nStack is empty\n";
	}
	else if(first==top){
		first=top=NULL;
	}
	else{
		stack *p=first;
		
		while(p!=NULL){
			if(p->next==top){
				p->next=NULL;
				break;
			}
			p=p->next;
		}
		top=p;
	}
}

stack* topp(){
	if(first==NULL){
		cout<<"\nStack is empty\n";
		return 0;
	}
	else{
		stack *p=first;
		while(p!=top){
			p=p->next;
		}
		return p;
	}
	
}
string reverse(){
	string s;
	if(top==NULL){
		cout<<"\nStack is empty\n";
	}
	else{
		//stack *p = first;
		stack *q;
		while(!isEmpty()){
			q=topp();
			s+=q->str;
			pop();
			
		
		}
		return s;
	}
}

void checkPalindrome(){
	cout<<"Enter a string: ";
	string str;
	cin>>str;
	string x;
	for(int i=0;i<str.length();i++){
		stack *curr=new stack;
		curr->str=str[i];
		push(curr);
	}
	x = reverse();
	if(x==str)
	cout<<"Palindrome";
	else
	cout<<"Not Palindrome";

	
}

int main(){
	checkPalindrome();
}
