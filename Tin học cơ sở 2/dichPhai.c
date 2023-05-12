#include<stdio.h>
int main(){
    int n;  scanf("%d", &n);
    int a[n];
    for(int i = 0 ; i < n; i++)     scanf("%d", &a[i]);
    int slpt;   scanf("%d", &slpt);
    for(int i = n-slpt; i < n; i++)   printf("%d ", a[i]);
    for(int i = 0 ; i< n-slpt; i++)   printf("%d ", a[i]);
    return 0;
}