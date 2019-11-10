/*
    "cStandard": "c89"
    -std=c89
*/

/*
    Greedy solution:
    1. Sort the lines based on initial position.
    2. Pick the lines that started at or before current position but ends last.
    3. Current position is now the end of the last chosen line.
    4. Remove all lines that end before the last chosen line's end.
    5. Repeat until reaching or exceeding M.
*/


#include<stdio.h>

#define MAX_LINES 100000

typedef struct LineDefinition{
    int leftEnd;
    int rightEnd;
}Line;

void swapLines(Line* a, Line* b) {
    Line temp = *a;
    *a = *b;
    *b = temp;
}

int compareLines(Line a, Line b){
    /*
        Line with lower leftEnd is sorted left
        If leftEnds are equal, line with smaller rightEnd is sorted left.
        Return: 0 -> a comes left, 1 -> b comes left
    */

    if(a.leftEnd!=b.leftEnd){
        return (a.leftEnd<b.leftEnd)? 0:1;
    }
    else{
        return (a.rightEnd<=b.rightEnd)? 0:1;
    }
}

int partition(Line lines[], int startIndex, int lastIndex){
    Line pivot = lines[lastIndex];
    int i = lastIndex;
    int j;
    for(j=startIndex; j<i; j++){
        if(compareLines(lines[j],pivot)!=0){
            /*Swap*/
            i--;
            swapLines(&lines[j],&lines[i]);
            j--;
        }
    }
    swapLines(&lines[lastIndex], &lines[i]);
    return i;
}

void quickSort(Line lines[], int startIndex, int lastIndex){
    if(startIndex<lastIndex){
        int pivotIndex = partition(lines, startIndex, lastIndex);
        quickSort(lines, startIndex, pivotIndex-1);
        quickSort(lines,pivotIndex+1,lastIndex);
    }
}

int main(){
    int M;
    int i,j;
    int numberOfLines = 0;

    Line lines[MAX_LINES + 3];

    /* Taking inputs */
    scanf("%d", &M);
    while(1){
        Line line;

        scanf("%d", &line.leftEnd);
        scanf("%d", &line.rightEnd);

        if(line.leftEnd==0 && line.rightEnd==0){
            break;
        }
        else{
            lines[numberOfLines] = line;
            numberOfLines++;
        }
    }

    /*Sort the lines*/
    quickSort(lines,0,numberOfLines-1);

    /*Greedy Solution*/
    Line solutions[numberOfLines];
    int numOfSelectedLines = 0;
    Line lastChosenLine = (Line){0,0};
    int maxRightEndIndex = 0;
    for(i=0; i<numberOfLines && lastChosenLine.rightEnd<M; i++){
        if(lines[i].rightEnd>lines[maxRightEndIndex].rightEnd){
                maxRightEndIndex = i;
        }
        if(i==numberOfLines-1 || lines[i+1].leftEnd > lastChosenLine.rightEnd){
            /* If this is last line, or the next line exceeds current rightEnd,
            consider current maxRightEndIndex as a potential solution*/
            if(lines[maxRightEndIndex].leftEnd<=lastChosenLine.rightEnd && lines[maxRightEndIndex].rightEnd > lastChosenLine.rightEnd){
                solutions[numOfSelectedLines] = lines[maxRightEndIndex];
                lastChosenLine = lines[maxRightEndIndex];
                numOfSelectedLines++;
            }
            else{
                break;
            }
        }
    }

    /*Print Solution*/
    if(solutions[numOfSelectedLines-1].rightEnd>=M){
        printf("%d\n",numOfSelectedLines);
        for(i=0; i<numOfSelectedLines;i++){
            printf("%d %d\n",solutions[i].leftEnd,solutions[i].rightEnd);
        }
    }
    else{
        printf("0\n");
    }
    return 0;
}
