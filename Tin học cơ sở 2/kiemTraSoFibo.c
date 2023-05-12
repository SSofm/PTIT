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
    printf("%d", checkFibo(n));
    return 0;
}