#include<stdio.h>
int min(int a, int b){
    return (a>b)?b:a;
}
int max(int a, int b){
    return (a>b)?a:b;
}
int main(){
    int a, b;   scanf("%d%d", &a, &b);
    long long ar[1000000];
    int run = 0;
    for(long long i = 1; i <= 1000000; i++)      ar[run++] = i*i;
    int dem = 0;
    int res[1000];
    for(long long i = 1; i <= 1000000; i++)      if(ar[i] >= min(a, b) && ar[i] <= max(a, b)){
       
        dem++;
    }
    printf("%d\n", dem);
    for(long long i = 1; i <= 1000000; i++)      if(ar[i] >= min(a, b) && ar[i] <= max(a, b)){
        printf("%d\n", ar[i]);
    }

    return 0;
}