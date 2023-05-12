#include<stdio.h>
int isPrime(int n){
    if(n<2) return 0;
    for(int i = 2; i*i <= n; i++)   if(n%i==0)  return 0;
    return 1;
}
int main(){
    int t;  scanf("%d", &t);
    int res = 0;
    while(t--){
        int n;  scanf("%d", &n);
        
        for(int i = 2; i <= n; i++){
            if(isPrime(i)){
                while(n%i==0){
                    res +=i;
                    n/=i;
                }
            }
        }
        
    }
    printf("%d\n", res);
    return 0;
}