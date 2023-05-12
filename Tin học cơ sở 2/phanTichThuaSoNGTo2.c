#include<stdio.h>
int isPrime(int n){
    if(n<2) return 0;
    for(int i = 2; i*i<= n; i++)    if(n%i==0)  return 0;
    return 1;
}
int main(){
    int n;  scanf("%d", &n);
    for(int i = 2; i <= n; i++){
        if(isPrime(i)){
            while(n%i==0){
                printf("%d", i);
                if(n>i) printf("x");
                n/=i;
            }
        }
    }
    return 0;
}