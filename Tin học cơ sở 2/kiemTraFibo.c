#include<stdio.h>
#include<math.h>

long long int checkSpare(long long int n){
    long long int s=  sqrt(n);
    return (s*s)==n;
}
long long int checkFibo(long long int n){
    return checkSpare(5*n*n - 4) || checkSpare(5*n*n +4);
}
int main(){
    int t;  scanf("%d", &t);
    while(t--){
        long long int n;  scanf("%lld", &n);
        if(checkFibo(n))    printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}