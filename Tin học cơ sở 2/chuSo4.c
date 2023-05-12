#include<stdio.h>
#include<math.h>
int thuanNghich(int n){
    int temp = 0;
    int m = n;
    while(n!=0){
        temp = temp * 10 + n%10;
        n/=10;
    }
    return (temp==m);
}
int checkSumOfDigit(int n){
    int sum = 0;
    while(n!=0){
        int temp = n%10;
        if(temp==4) return 0;
        sum += temp;
        n/=10;
    }
    return (sum%10==0);
}
int main(){
    int t;  scanf("%d", &t);
    while(t--){
        int n;  scanf("%d", &n);
        for(int i = pow(10, n-1); i < pow(10, n); i++){
            if(thuanNghich(i) && checkSumOfDigit(i))    printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}