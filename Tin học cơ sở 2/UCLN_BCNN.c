#include<stdio.h>
long long ucln(long long a, long long b){
    while(a!=b){
        if(a>b) a-=b;
        else b -=a;
    }
    return a;
}
int main(){
    long long a, b;   scanf("%ld%ld", &a, &b);
    printf("%ld\n%ld", ucln(a, b), (long long)(a*b)/ucln(a, b));
    return 0;
}