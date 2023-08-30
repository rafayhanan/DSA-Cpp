#include<iostream>
#include<string>
using namespace std;

class stack{
	int top;
	int size;
	string* a;
	
	public:
	stack(int s){
		top=-1;
		size =s;
		a = new string[size];
	} 
	void push(string);
	void pop();
	string peek();
	void display();
	bool isEmpty();
	bool isFull();
};

bool stack::isEmpty(){
	return top==-1;
}

bool stack::isFull(){
	return top==size-1;
}
void stack::push(string str){
	if(top==size-1){
		cout<<"\nStack is full\n";
	}
	else{
		a[++top]=str;
	}
}

void stack::pop(){
	if(top==-1){
		cout<<"\nStack is empty\n";
	}
	else{
		a[top--];
		
	}
}

string stack::peek(){
	if(top==-1){
		cout<<"\nStack is empty\n";
	}
	else{
		return a[top];
		
	}
}

void stack::display(){
	if(top==-1){
		cout<<"Stack empty\n";
	}
	else
	{
		int x = top;
		for(int i=0;i<=x;i++){
			cout<<peek();
			pop();
		}
	}
}

bool isBalanced(string braces){
	stack s(50);
	int i= 0;
	string x;
	while(i!=braces.length()){
		if(braces[i]=='('){
			x=braces[i];
			s.push(x);
			i++;
		}
		else if(braces[i]==')'){
		
				if(s.isEmpty()){
					return false;
				}
			else{
			
			s.pop();
		}
			i++;
		}
		}
		if(!s.isEmpty()){
			return false;
			
		}
		else
			return true;
}

int main(){
	string a = "((()))";
	cout<<isBalanced(a);
}

