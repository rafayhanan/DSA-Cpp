#include <iostream>
using namespace std;

#define s 5

void merge(int arr[], int left[], int left_size, int right[], int right_size)
{
   	
    int i = 0, j = 0;

    while (i < left_size && j < right_size)
    {
        
        if (left[i] < right[j])
        {
            arr[i + j] = left[i];
            i++;
        }
        else
        {
            arr[i + j] = right[j];
            j++;
        }
    }

    
    while (i < left_size)
    {
        arr[i + j] = left[i];
        i++;
    }

    
    while (j < right_size)
    {
        arr[i + j] = right[j];
        j++;
    }
}


void mergeSort(int arr[], int n)
{
    
    if (n < 2)
    {
        return;
    }

   
    int mid = n / 2;
    int left[mid];
    int right[n - mid];

 
    for (int i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }

    for (int i = mid; i < n; i++)
    {
        right[i - mid] = arr[i];
    }

   
    mergeSort(left, mid);
    mergeSort(right, n - mid);

 
    merge(arr, left, mid, right, n - mid);
}



int main()
{
    
    int arr[s] = {5, 2, 8, 1, 9};
    

    mergeSort(arr, s);

    
    for (int i = 0; i < s; i++)
    {
        cout << arr[i] << " ";
    }

}

