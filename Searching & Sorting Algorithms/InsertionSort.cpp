#include<iostream>
using namespace std;

#define s 5

void insertionSort(int arr[]){
	for(int i=1;i<s;i++){
		int curr = arr[i];
		
		int j=i-1;
		
		while(j>=0 && arr[j]>curr){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]= curr;
		
	}
}

int main(){
	int arr[s] = {4, 3, 7, 2, 8};

	insertionSort(arr);
	
	for (int i = 0; i < s; i++) {
		cout << arr[i] << " ";
}
		cout << endl;
}
