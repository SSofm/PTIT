#include<stdio.h>
int tongChuSo(int n){
    int res = 0;
    while(n!=0){
        res += n%10;
        n/=10;
    }
    return (res%10==8);
}
int checkThuanNghich(int n){
    int temp = 0;
    int m = n;
    while(n!=0){
        temp = temp * 10 + n%10;
        n/=10;
    }
    return (temp==m);
}
int checkDigit(int n){
    int dem = 0;
    while(n!=0){
        if((n%10)==6)   dem++;
        n/=10;
    }
    return (dem>=1);
}
int min(int a, int b){
    return (a>b)?b:a;
}
int max(int a, int b){
    return (a>b)?a:b;
}
int main(){
    int a, b;   scanf("%d%d", &a, &b);
    for(int i = min(a, b); i <= max(a, b); i++){
        if(checkDigit(i)&&tongChuSo(i)&&checkThuanNghich(i))    printf("%d ", i);
    }
    return 0;
}