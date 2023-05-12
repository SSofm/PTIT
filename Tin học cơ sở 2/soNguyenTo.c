#include<stdio.h>
int isPrime(long long n){
    if(n<2) return 0;
    for(int i = 2; i * i <= n; i++) if(n%i==0)  return 0;
    return 1;
}
int main(){
    int t;  scanf("%d", &t);
    while(t--){
        long long n;    scanf("%ld", &n);
        if(isPrime(n)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}