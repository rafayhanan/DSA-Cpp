#include<iostream>
using namespace std;


class Que{
	public:
		int size;
		int *q;
		int front;
		int rear;
	
		
	public:
		Que(int x){
		size=x;
		q = new int[size];
		front=-1;
		rear=-1;
	}
	
	bool isEmpty();
	bool isFull();
	void display();
	void enqueue(int x);
	int dequeue();	
};

bool Que::isEmpty(){
	if(rear==-1 && front==-1){
		return true;
	}
	else
		return false;
}

bool Que::isFull(){
	if((rear+1)%size==front)
		return true;
	else
		return false;	
}

void Que::enqueue(int x){
	if(isFull()){
		cout<<"Queue is full";
	}
	else if(isEmpty()){
		front=rear=0;
		q[rear]=x;
	}
	else{
		rear=(rear+1)%size;
		q[rear]=x;
	}
}

int Que::dequeue(){
	if(isEmpty()){
		cout<<"Queue is Empty.";
		return 0;
	}
	else{
		int val = q[front];
		if(front=rear){
			front=rear=-1;
		}
		else{
			front=(front+1)%size;
		}
	return val;	
	}
}

void Que::display(){
	if(isEmpty()){
		cout<<"Queue Empty.";
	}
	else{
		 int i = front;
            cout<<"Orders by order: ";
            do
            {
                cout<<"\n"<<q[i];
                i = (i+1)%size;
            }
			while(i!=(rear+1)%size);

	}
}


int main(){
cout<<"WELCOME TO PIZZA HUT\n\n";
cout<<"Enter M orders: ";
int M;
cin>>M;
Que q(M);	
	
int counter=0;
int choice =0;
	
	
	do{
	cout<<"\n\n1-Place Order.\n2-Deliver Orders.\n3-Display Current Orders.\n4-Exit.\n";
	cout<<"\nChoice: ";
	cin>>choice;
	
	switch(choice){
		case 1:
			counter++;
			q.enqueue(counter);
			break;
		case 2:
			while(!q.isEmpty()){
				q.dequeue();
			}
			cout<<"\nAll Orders Delivered.";
			break;
		case 3:
			q.display();
			break;
		case 4:
			choice=4;
			break;
			
		default:
		cout<<"\nInvalid Choice.";
		break;	
	}
}while(choice!=4);
	
}
