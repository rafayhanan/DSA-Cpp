#include<iostream>
#include<string>
using namespace std;


class stack{
	int top;
	int size;
	int* a;
	
	public:
	stack(int s){
		top=-1;
		size =s;
		a = new int[size];
	} 
	void push(int);
	void pop();
	int peek();
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
void stack::push(int str){
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

int stack::peek(){
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

int operand(string str){
	if(str=="+"){
		return 1;
	}
	if(str=="-"){
		return 2;
	}
	if(str=="*"){
		return 3;
	}
	if(str=="/"){
		return 4;
	}
}

int conversion(string postfix){
	int infix;
	
	int i=0;
	stack s(20);
	string x;
	int value;
	while(i!=postfix.length()){
		if(postfix[i]>='0' && postfix[i]<='9'){
			x=postfix[i];
            value = stoi(x);
			s.push(value);
			i++;
		}
		else{
			x=postfix[i];
			if(operand(x)==1){
				value=s.peek();
				s.pop();
				infix=(value+s.peek());
				s.pop();
				s.push(infix);
                i++;
			}
			else if(operand(x)==2){
				value=s.peek();
				s.pop();
				infix=(s.peek()-value);
				s.pop();
				s.push(infix);
                i++;
			}
			else if(operand(x)==3){
				value=s.peek();
				s.pop();
				infix=(s.peek()*value);
				s.pop();
				s.push(infix);
                i++;
			}
			else if(operand(x)==4){
				value=s.peek();
				s.pop();
				infix=(s.peek()/value);
				s.pop();
				s.push(infix);
                i++;
			}
		}
	}
	infix = s.peek();
	s.pop();
	return infix;
}

int main(){
	int a = conversion("12+3*");
	cout<<a;
}
