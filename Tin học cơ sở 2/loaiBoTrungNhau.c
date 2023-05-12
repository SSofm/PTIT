#include<stdio.h>
int main(){
    int n;  scanf("%d", &n);
    int a[n];
    for(int i = 0 ; i < n; i++) scanf("%d", &a[i]);
    printf("%d ", a[0]);
    for(int i = 1; i < n; i++){
        int check = 0;
        for(int j = i-1; j >= 0; j--){
            if(a[j] ==a[i]){
                check = 1;
                break;
            }
        }
        if(check==0)    printf("%d ", a[i]);
    }
    return 0;
}