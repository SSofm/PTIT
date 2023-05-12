#include<stdio.h>
int main(){
    int t;  scanf("%d", &t);
    while(t--){
        int n;scanf("%d", &n);
        int a[n];
        for(int i = 0; i < n; i++)  scanf("%d", &a[i]);
        int res = 1;
        for(int i = 1; i < n; i++){
            int check= 0;
            for(int j = i-1; j >= 0; j--){
                if(a[j] > a[i]){
                    check = 1;
                    break;
                }
            }
            if(check==0)    res++;
        }
        printf("%d\n", res);
    }
    return 0;
}