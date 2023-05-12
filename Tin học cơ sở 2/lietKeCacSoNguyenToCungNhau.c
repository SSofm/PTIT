#include<stdio.h>
long long gcd(long long a, long long b){
    while(a!=b){
        if(a>b) a-=b;
        else b-=a;
    }
    return a;
}
int min(int a, int b){
    return (a>b)?b:a;
}
int max(int a, int b){
    return (a>b)?a:b;
}
int main(){
    int a, b;   scanf("%d%d", &a, &b);
    int d = min(a, b);
    int c = max(a, b);
    for(int i = d; i <= c; i++){
        for(int j = i+1; j <= c; j++){
            if(gcd(i, j) == 1)  printf("(%d,%d)\n", i, j);
        }

    }
    return 0;
}