#include<stdio.h>
int main(){
    int n;  scanf("%d", &n);
    int a[n];
    for(int i = 0 ; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0 ; i < n; i++){
        for(int j = i+1; j< n; j++){
            if(a[j] > a[i]){
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
    printf("%d ", a[0]);
    for(int i = 1; i < n; i++)  if(a[i]!=a[0]){
        printf("%d", a[i]);
        break;
    }
    return 0;
}