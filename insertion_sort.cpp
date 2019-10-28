#include<iostream>

using namespace std;

void insertionSort(int* array, int size){
    for(int i=1; i<size; i++){
        int j = i-1;
        int key = array[i];
        while(j>=0 && key<array[j]){
            array[j+1] = array[j];
            j--;
        }
        array[j+1]= key;
    }
}

void printArray(int* array, int size){
    cout<< "Array: ";
    for(int i=0; i<size; i++){
        cout<< array[i] <<" ";
    }
    cout<<endl;
}

int main(){
    int a[] = {9,7,5,3,1,2,4,6,8,0};
    insertionSort(a, 10);
    printArray(a,10);
    
    return 0;
}