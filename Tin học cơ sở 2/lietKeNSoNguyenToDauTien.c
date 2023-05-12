#include<stdio.h>
#include<string.h>

int isPrime[2001111];
int main(){
   
    // sang nguyen to
    memset(isPrime, 1, sizeof(isPrime));
    for(int i = 2;i * i <= 2000000; i++){
        if(!isPrime[i]) continue;
        for(int j = i*i; j <= 2000000; j+=i)
            isPrime[j] = 0;
    }
    isPrime[1] = 0;
    int n;  scanf("%d", &n);
    
    for(int i = 2; i <= 2000005; i++){
        if(n<=0) break;
        if(isPrime[i]){
            printf("%d\n", i);
            --n;
        }
    }
   
    return 0;
}