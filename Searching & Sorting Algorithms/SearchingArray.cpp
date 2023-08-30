#include<iostream>
using namespace std;

#define s 20
int arr[s];

void linearSearch(int key){
	for(int i=0;i<s;i++){
		if(arr[i]==key){
			cout<<"Found\n";
			return;
		}
		
	}
	cout<<"Not found\n";
}

void binarySearch(int SI,int LI,int key){
	int mid = (SI+LI)/2;
	if(key==arr[mid]){
		cout<<"Found\n";
	}
	if(SI>=LI){
		cout<<"Not found\n";
	}
	else if(key > arr[mid]){
		binarySearch(mid+1,LI,key);
	}
	else if(key < arr[mid]){
		binarySearch(SI,mid-1,key);
	}
}

int main(){
	for(int i=0;i<s;i++){
		arr[i]=(i+1);
	} 
	
	linearSearch(5);
	binarySearch(0,s-1,21);
}
