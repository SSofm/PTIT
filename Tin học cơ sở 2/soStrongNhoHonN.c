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
    for(int i = 1; i < n; i++)  if(check(i))    printf("%d ", i);
    return 0;
}