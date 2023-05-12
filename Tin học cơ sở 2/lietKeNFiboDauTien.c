#include<stdio.h>
#include<math.h>

int checkSpare(int n){
    int s=  sqrt(n);
    return (s*s)==n;
}
int checkFibo(int n){
    return checkSpare(5*n*n - 4) || checkSpare(5*n*n +4);
}

int main(){
    int n;  scanf("%d", &n);
    int a[n];
    a[0] = 0;
    a[1] = 1;
    for(int i = 2; i < n; i++){
        a[i] = a[i-1] + a[i-2];
    }    
    for(int i = 0 ; i < n; i++) printf("%d ", a[i]);
    return 0;
}