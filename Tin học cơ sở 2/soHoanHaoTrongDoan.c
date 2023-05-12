#include<stdio.h>
int min(int a, int b){
    return (a<b)?a:b;
}
int max(int a, int b){
    return (a>b)?a:b;
}
int checkPerfectNum(int n){
    int sum = 1;
    for(int i = 2; i * i <= n; i++){
        if(n%i==0){
            if(i*i!=n)  sum += (i+n/i);
            else sum += i;
        }
    }
    if(sum==n && n!=1)  return 1;
    return 0;
}
int main(){
    int a, b;   scanf("%d%d", &a, &b);
    for(int i = min(a, b); i <= max(a, b); i++) if(checkPerfectNum(i))  printf("%d ", i);
    return 0;
}