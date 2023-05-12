#include<stdio.h>
int checkPerfectNum(int n){
    int m = n;
    int resCheck = 0;
    for(int i = 1;  i< n; i++)  if(n%i==0)  resCheck+=i;
    return resCheck==m;
}
int main(){
    int n;  scanf("%d", &n);
    printf("%d", checkPerfectNum(n));
    return 0;
}