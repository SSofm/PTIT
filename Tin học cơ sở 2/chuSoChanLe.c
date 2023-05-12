#include<stdio.h>
int main(){
    int n;    scanf("%d", &n);
    // printf("%d", n);
    int r1 = 0;
    int r2 = 0;
    while(n!=0){
        int t = n%10;
        if(t%2!=0) r1++;
        if(t%2==0) r2++; 
        // printf("%d\n", n%10);
        n/=10;
    }
    printf("%d %d", r1, r2);
    // return 0;
}