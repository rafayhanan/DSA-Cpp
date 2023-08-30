#include<iostream>
using namespace std;

#define s 5

void selectionSort(int arr[]){
	for(int i=0;i<s-1;i++){
		int minIndex=i;
		for(int j=i+1;j<s;j++){
			if(arr[minIndex]>arr[j]){
				minIndex=j;
			}
		}
		swap(arr[minIndex],arr[i]);
	}
}

int main(){
	int arr[s] = {4, 3, 7, 2, 8};
	
	selectionSort(arr);
	
	for (int i = 0; i < s; i++) {
		cout << arr[i] << " ";
}
		cout << endl;
}
