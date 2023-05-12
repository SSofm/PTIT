#include<stdio.h>
int main(){
    int n; scanf("%d", &n);
    int m1 = n;
    int m2 = n;
    int res = 0;
    int c = m1%10;
    int d = 0;
    while(n!=0){
        res++;
        if(n < 10) d=n;
        n/=10;

    }
    if(c!=0)
    printf("%d", c);
    int a[res];
    int run = 0;
    while(m2!=0){
        a[run++] = m2%10;
        m2/=10;
    }
    for(int i = res-2; i >= 1; i--) printf("%d", a[i]);
    printf("%d", d);

    
    return 0;
}