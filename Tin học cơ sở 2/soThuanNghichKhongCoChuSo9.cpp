#include<stdio.h>
int check(int n){
    int temp = 0;
    int m = n;
    while(n!=0){
        int tg = n%10;
        if(tg==9)   return 0;
        temp = temp * 10 + tg;
        n/=10;
    }
    return (temp==m);
}
int main(){
    int n;  scanf("%d", &n);
    int dem = 0;
    for(int i = 2; i < n; i++)  if(check(i)){
        dem++;
        printf("%d ", i);
    }
    printf("\n%d", dem);
    return 0;
}