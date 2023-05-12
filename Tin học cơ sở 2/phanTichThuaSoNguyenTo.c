#include<stdio.h>
int isPrime(int n){
    if(n<2) return 0;
    for(int i = 2; i *i <= n; i++)  if(n%i==0)  return 0;
    return 1;
}
int main(){
    int t;      scanf("%d", &t);
    while(t--){
        int n;  scanf("%d", &n);
        for(int i = 2; i<= n; i++){
            while(n%i==0){
                if(isPrime(i)){
                    printf("%d ", i);
                }   
                n/=i;
            }
        }
        printf("\n");
    }
    return 0;
}