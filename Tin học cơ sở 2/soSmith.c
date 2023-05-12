#include<stdio.h>
int isPrime(int n){
    if(n<2) return 0;
    for(int i = 2; i *i <= n; i++)  if(n%i==0)  return 0;
    return 1;
}
int tongChuSo(int n){
    int res = 0;
    while(n!=0){
        res += n%10;
        n/=10;
    }
    return res;
}
int sumOfDigitPrime(int n){
    int sum = 0;
    for(int i = 2; i <= n; i++){
        if(isPrime(i)){
            while(n%i==0){
                sum += tongChuSo(i);
                n/=i;
            }
        }
    }
    return sum;
}
int main(){
    int n;  scanf("%d", &n);
    if(sumOfDigitPrime(n) == tongChuSo(n))  printf("YES\n");
    else printf("NO\n");
    return 0;
}