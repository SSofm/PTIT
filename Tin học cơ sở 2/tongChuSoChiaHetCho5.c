#include<stdio.h>
int isPrime(int n){
    if(n<2) return 0;
    for(int i = 2; i * i <= n; i++)    if(n%i==0)  return 0;
    return 1;
}
int tongChuSo(int n){
    int res = 0;
    while(n!=0){
        res += n%10;
        n/=10;
    }
    return (res%5==0);
}
int main(){
    int n;  scanf("%d", &n);
    int dem = 0;
    for(int i = 5; i < n; i++){
        if(isPrime(i) && tongChuSo(i)){
            dem++;
            printf("%d ", i);
        }
    }
    printf("\n%d", dem);
    return 0;
}