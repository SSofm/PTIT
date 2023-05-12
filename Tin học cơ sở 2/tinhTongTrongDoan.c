#include<stdio.h>
int min(int a, int b){
    return (a<b)?a:b;
}
int max(int a, int b){
    return (a>b)?a:b;
}
int main(){
    int a, b;   scanf("%d%d", &a, &b);
    int res = 0;
    for(int i = min(a, b); i <= max(a, b); i++) res+=i;
    printf("%d", res);
    return 0;
}