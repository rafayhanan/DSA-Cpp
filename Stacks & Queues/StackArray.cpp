#include<iostream>
#include<string>
using namespace std;

int top=-1;
int size = 10;
string Stack[10];



void push(string str){
	if(top==size-1){
		cout<<"\nStack is full\n";
	}
	else{
		Stack[++top]=str;
	}
}

void pop(){
	if(top==-1){
		cout<<"\nStack is empty\n";
	}
	else{
		Stack[top--];
		
	}
}

string peek(){
	if(top==-1){
		cout<<"\nStack is empty\n";
	}
	else{
		return Stack[top];
		
	}
}

void display(){
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

void checkPalindrome(){
	cout<<"Enter a String: ";
	string str;
	cin>>str;
	
	string s;
	for(int i=0;i<str.length();i++){
		s=str[i];
		push(s);
	}
	//display();
	
	string temp;
	
	int x= top;
	for(int i=0;i<=x;i++){   //reversing the string
		temp = temp + peek();
		pop();
	}
	
	if(str==temp){
		cout<<"\nPalindrome\n";
	}
	else
		cout<<"\nNot Palindrome\n";
}

int main(){
	checkPalindrome();
}
