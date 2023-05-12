#include<stdio.h>
int min(int a, int b){
    return (a>b)?b:a;
}
int max(int a, int b){
    return (a>b)?a:b;
}
int isPrime(int n){
    if(n<2) return 0;
    for(int i = 2; i * i <= n; i++) if(n%i==0)  return 0;
    return 1;
}
int thuanNghich(int n){
    int m = n;
    int temp = 0;
    while(n!=0){
        temp = temp * 10 + n%10;
        n/=10;
    }
    return (temp==m);
}
int main(){
    int t;  scanf("%d", &t);
    while(t--){
        int a, b;   scanf("%d%d", &a, &b);
        int breakLine = 0;
        for(int i = min(a, b); i <= max(a, b); i++){
            
            if(isPrime(i) && thuanNghich(i)){
                if(breakLine%10==0){
                    printf("\n");
                      
                } 
                printf("%d ", i);
                breakLine++;
            }    
        }
        printf("\n");
    }
    return 0;
}