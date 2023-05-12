#include<stdio.h>
int main(){
    int a, b;   scanf("%d%d", &a, &b);
    if(b==0)    printf("0");
    else
    printf("%d\n%d\n%ld\n%d\n%d\n%.2f", a+b, a-b, (long long)a*b, a/b, a%b, (float)a/b);
    return 0;
}