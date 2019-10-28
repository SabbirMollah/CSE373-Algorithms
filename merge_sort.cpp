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

void merge(int* array, int startIndex, int midIndex, int lastIndex){
    // Merges sorted Array(startIndex .... midIndex), with 
    // sorted Array(midIndex+1 .... lastIndex+1) into one sorted Array

    int firstArraySize = midIndex - startIndex + 1;
    int secondArraySize = lastIndex - midIndex;

    int firstArray[firstArraySize];
    int secondArray[secondArraySize];

    for(int i=0, j = startIndex; i<firstArraySize; i++, j++){
        firstArray[i] = array[j];
    }

    for(int i=0, j= midIndex+1; i<secondArraySize; i++, j++){
        secondArray[i] = array[j];
    }
    
    int firstArrayIndex = 0;
    int secondArrayIndex = 0;
    int index = startIndex;
    while(firstArrayIndex != firstArraySize &&  secondArrayIndex != secondArraySize){
        if(secondArray[secondArrayIndex] <= firstArray[firstArrayIndex]){
            array[index] = secondArray[secondArrayIndex];
            secondArrayIndex++;
        }
        else if(firstArray[firstArrayIndex] <= secondArray[secondArrayIndex]){
            array[index] = firstArray[firstArrayIndex];
            firstArrayIndex++;
        }
        index++;
    }
    while(secondArrayIndex != secondArraySize){
        array[index] = secondArray[secondArrayIndex];
        secondArrayIndex++;
        index++;
    }
    while(firstArrayIndex != firstArraySize){
        array[index] = firstArray[firstArrayIndex];
        firstArrayIndex++;
        index++;
    }


}

void mergeSort(int* array, int startIndex, int lastIndex){
    int midIndex = (startIndex+lastIndex) / 2;

    if(startIndex<lastIndex){
        mergeSort(array, startIndex, midIndex); //Inclusive inclusive
        mergeSort(array, midIndex+1, lastIndex); 
        merge(array, startIndex, midIndex, lastIndex);
    }
}

int main(){
    int a[] = {5,3,7,4,10,100,9,9,10,2};
    mergeSort(a,0, 9);
    printArray(a,0,9);
    return 0;
}