#include<stdio.h>
#include<string.h>
#include<math.h>
long long checkThuanNghich(long long n){
    long long m = n;
    long long temp = 0;
    while(n!=0){
        temp = temp * 10 + n%10;
        n/=10;
    }
    return (temp==m);
}

long long tongChuSo(long long n){
    long long res = 0;
    while(n!=0){
        res += n%10;
        n/=10;
    }
    return res;
}

int main(){
    int t;  scanf("%d", &t);
    while(t--){
        long long n;  scanf("%lld", &n);
        long long dem = 0;
        for(int i = pow(10, n-1); i < pow(10, n); i++)
            if(checkThuanNghich(i) && tongChuSo(i)%10==0) dem++;
        printf("%ld\n", dem);
    }
    return 0;
}