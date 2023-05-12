#include<stdio.h>
int main(){
    int t;  scanf("%d", &t);
    while(t--){
        long long n;    scanf("%ld", &n);
        int sumTest = 0;
        while(n!=0){
            sumTest+=n%10;
            n/=10;
        }
        if(sumTest%10==0)   printf("YES\n");
        else printf("NO\n");

    }
    return 0;
}