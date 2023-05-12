#include<stdio.h>
int tongChuSo(int n){
    int res = 0;
    while(n!=0){
        res += n%10;
        n/=10;
    }
    return res;
}
int main(){
    int a, b;   scanf("%d%d", &a, &b);
    if(tongChuSo(a) <= tongChuSo(b))    printf("%d %d", a, b);
    else if(tongChuSo(a)>tongChuSo(b))  printf("%d %d", b, a);
    return 0;
}