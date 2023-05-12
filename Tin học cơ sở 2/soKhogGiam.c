#include<stdio.h>
#include<math.h>
int check(int n, int slcs){
    int a[slcs];
    int run = 0;
    while(n!=0){
        a[run++] = n%10;
        n/=10;
    }
    for(int i = 0 ; i < slcs-1; i++){
        // printf("%d ", a[i]);
        if(a[i+1] > a[i])   return 0;
    }
    return 1;
}
int checkEqualDgit(int n, int slcs){
    int a[slcs];
    int run = 0;
    while(n!=0){
        a[run++] = n%10;
        n/=10;
    }
    for(int i = 0 ; i < slcs-1; i++)    if(a[i]!=a[i+1])    return 0;
    return 1;
}
int main(){
    
    int t;  scanf("%d", &t);
    while(t--){
        int n;  scanf("%d", &n);
        for(int i = 1; i <= 9; i++){
            for(int j = i; j <= n; j++){
                printf("%d ", );
            }
        }
    }
    return 0;
}