#include<iostream>
using namespace std;

#define s 8
int arr[s];							
bool occupied[s];                  

bool allOccupied(){
	for(int i=0;i<s;i++){
		if(!occupied[i]){
			return false;
		}
	}
	return true;
}

void insert(int index,int x){
	if(allOccupied()){
		cout<<"No space\n";
	}
	else if(index>s-1){
		insert(0,x);
	}
	else if(!occupied[index]){
		arr[index]=x;
		occupied[index]=true;
	}
	else{
		if(index==s-1){
			insert(0,x);
		}
		else{
			insert(index+1,x);
		}	
	}
}

void hashInsert(int x){
	int index = x%s; //s=10
	insert(index,x); 
}

void hashdelete(int x){
	for(int i=0;i<s;i++){
		if(arr[i]==x){
			arr[i]=0;
			occupied[i]=false;
		}
	}
}

void display(){
	for(int i=0;i<s;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
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
	 menu();
}
