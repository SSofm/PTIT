#include<stdio.h>
int main(){
    int t;  scanf("%d", &t);
    while(t--){
        int odd= 0;
        int even = 0;
        int n;  scanf("%d", &n);
        while(n!=0){
            int temp = n%10;
            if(temp%2!=0)   odd++;
            else even++;
            n/=10;
        }
        printf("%d %d\n", odd, even);
    }
    return 0;
}