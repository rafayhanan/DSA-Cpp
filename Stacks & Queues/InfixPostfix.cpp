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

int priroty(string x){
	if(x=="+"||x=="-"){
		return 1;
	}
	if(x=="*"||x=="/"){
		return 2;
	}
}

string postfix(string infix){
	string postfix="";
	stack s1(50);
	int i=0;
	string s;
	while(i!=infix.length()){
		if(infix[i]>='a' && infix[i]<='z'||infix[i]>='A'&&infix[i]<='Z'){
			postfix+=infix[i];
			i++;
		}
		else if(infix[i]=='('){
			s=infix[i];
			s1.push(s);
			i++;
		}
		else if(infix[i]==')'){
			while(s1.peek()!="("){
				postfix+=s1.peek();
				s1.pop();
			}
			s1.pop();
			i++;
		}
		else{
			s=infix[i];
			while(!s1.isEmpty() && priroty(s)<=priroty(s1.peek())){
				postfix+=s1.peek();
				s1.pop();
			}
			s=infix[i];
			s1.push(s);
			i++;
		}
	}
	while(!s1.isEmpty()){
		postfix+=s1.peek();
		s1.pop();
	}
	return postfix;
}

int main(){
	string pf = postfix("a+b-c(f+g/e)");
	cout<<pf;
}




