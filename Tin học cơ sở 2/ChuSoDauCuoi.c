#include<stdio.h>
int main(){
    int n; scanf("%d", &n);
    int m1 = n;
    int m2 = n;
    int res = 0;
    int c = m1%10;
    int d = 0;
    while(n!=0){
        res++;
        if(n < 10) d=n;
        n/=10;

    }
    
 
    printf("%d %d", d, c);
    return 0;
}