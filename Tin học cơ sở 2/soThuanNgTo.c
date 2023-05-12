#include<stdio.h>
int isPrime(int n){
    if(n<2) return 0;
    for(int i = 2; i*i <= n; i++)   if(n%i==0)  return 0;
    return 1;
}
int digit(int n){
    while(n!=0){
        if(!isPrime(n%10))  return 0;
        n/=10;
    }
    return 1;
}
int tongChuSo(int n){
    int res = 0;
    while(n!=0){
        res += n%10;
        n/=10;
    }
    return isPrime(res);
}
int min(int a, int b){
    return (a>b)?b:a;
}
int max(int a, int b){
    return (a>b)?a:b;
}
int main(){
    int t;  scanf("%d", &t);
    while(t--){
        int a, b;   scanf("%d%d", &a, &b);
        int dem = 0;
        for(int i = min(a, b); i <= max(a, b); i++){
            if(digit(i) && tongChuSo(i) && isPrime(i))  dem++;
        }
        printf("%d\n", dem);
    }
    return 0;
}