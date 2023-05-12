#include<stdio.h>
#include<math.h>
int checkNT(int n){
    if(n<2) return 0;
    for(int i = 2; i * i <= n; i++) if(n%i==0)  return 0;
    return 1;
}
int tongChuSo(int n){
    int tong = 0;
    while(n!=0){
        tong += n%10;
        n/=10;
    }
    return tong;    
}
int isPerfectSquare(int n){
    int s = sqrt(n);
    return (s*s==n);
}
int checkFibo(int n){
    return (isPerfectSquare(5*n*n-4) || isPerfectSquare(5*n*n+4));
}
int min(int a, int b){
    return (a<b)?a:b;
}
int max(int a, int b){
    return (a>b)?a:b;
}
int main(){
    int a, b;   scanf("%d%d", &a, &b);
    for(int i = min(a, b); i < max(a, b); i++){
        if(checkFibo(tongChuSo(i))&&checkNT(i))   printf("%d ", i);
    }
    return 0;
}