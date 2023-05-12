#include<stdio.h>
int main(){
    int t;  scanf("%d", &t);
    while(t--){
        int n;  scanf("%d", &n);
        int res = 0;
        for(int i= 1; i *i <= n; i++){
            if(n%i==0){
                if(i%2==0)      res++;
                if(i!=(n/i)){
                    if((n/i)%2==0)  res++;
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}