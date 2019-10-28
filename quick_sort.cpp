#include<iostream>

using namespace std;

void printArray(int* array, int start, int end){
    cout<< "Array: ";
    cout<<"Start "<<start<<" End "<<end<<" ||| ";
    for(int i=start; i<=end; i++){
        cout<< array[i] <<" ";
    }
    cout<<endl;
}

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition(int arr[], int startIndex, int lastIndex){
    int pivot = arr[lastIndex];
    int i = lastIndex;

    for(int j=startIndex; j<i; j++){
        if(arr[j]>=pivot){
            //Swap
            i--;
            swap(arr[j],arr[i]);
            j--;
        }
    }
    swap(&arr[lastIndex], &arr[i]);
    return i;
}

void quickSort(int arr[], int startIndex, int lastIndex){
    if(startIndex<lastIndex){
        int pivotIndex = partition(arr, startIndex, lastIndex);
        quickSort(arr, startIndex, pivotIndex-1);
        quickSort(arr,pivotIndex+1,lastIndex);
    }
}

int main(){
    int arr[] = {5,3,8,4,10,100,9,9,10,8};
    quickSort(arr,0,9);
    printArray(arr,0,9);
    
    return 0;
}