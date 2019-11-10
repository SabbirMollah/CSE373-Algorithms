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
            swap(&arr[j],&arr[i]);
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
    int arr[] = {11,10,9,8,7,6,5,4,3,2,1};
    quickSort(arr,0,10);
    printArray(arr,0,10);
    
    return 0;
}