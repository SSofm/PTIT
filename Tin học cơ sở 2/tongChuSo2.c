#include<stdio.h>
int main(){
    int t;  scanf("%d", &t);
    while(t--){
        int n;  scanf("%d", &n);
    int res = 0;
    while(n!=0){
        res+=n%10;
        n/=10;
    }
    printf("%d\n", res);
    }
    
    return 0;
}