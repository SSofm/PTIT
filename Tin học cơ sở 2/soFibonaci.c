#include<stdio.h>
long long a[100];

int main(){
    int t;  scanf("%d", &t);
    while(t--){
        int n;  scanf("%d", &n);
        a[0] = 0;
        a[1] = 1;    
        
        for(int i = 2; i <= 100; i++)   a[i] = a[i-1] + a[i-2];
        printf("%ld\n", a[n]);
        // printf("%d", a[1]);
    }
    return 0;
}