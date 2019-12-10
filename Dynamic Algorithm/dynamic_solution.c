#include<stdio.h>

int memo[36][33];

int AweSum(int k, int n){
    if(k==0) return n;
    else if(n==1) return 1;
    else if(memo[k][n]!=-1) return memo[k][n];
    else{
        memo[k][n] = AweSum(k-1,n) + AweSum(k,n-1);
        return memo[k][n];
    } 
}

int main(){
    
    int i,j;
    int k, n;
    scanf("%d%d",&k,&n);
    for(i=0; i<36; i++){
        for(j=0; j<33; j++){
            memo[i][j] = -1;
        }
    }
    printf("%d",AweSum(k,n));
    return 0;
}