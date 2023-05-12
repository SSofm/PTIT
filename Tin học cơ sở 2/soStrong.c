#include<stdio.h>
int giaiThua(int n){
    int res = 1;
    for(int i = 2; i<= n; i++)  res *=i;
    return res;
}
int check(int n){
    int m = n;
    int sum = 0;
    while(n!=0){
        sum += giaiThua(n%10);
        n/=10;
    }
    return (sum==m);
}
int main(){
    int n;  scanf("%d", &n);
    printf("%d", check(n));
    return 0;
}