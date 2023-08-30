#include <iostream>

using namespace std;

#define s 5

void bubbleSort(int arr[]){
	int last = s-1;
	for(int i=0;i<s-1;i++){
		for(int j=0;j<last;j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j],arr[j+1]);
			}
		}
		last--;
	}
}

int main() {
int arr[s] = {4, 3, 7, 2, 8};

bubbleSort(arr);

for (int i = 0; i < s; i++) {
cout << arr[i] << " ";
}
cout << endl;


}
