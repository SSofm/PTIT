#include<stdio.h>
int main(){
    int n;  scanf("%d", &n);
    int a[n];
    int duyet[n];
    for(int i = 0 ; i < n; i++){
        scanf("%d", &a[i]);
        duyet[i] = 0;
    } 
    int empty = 0;
    for(int i = 0 ; i < n; i++){
        int check = 0;
        for(int j = i+1; j <= n; j++){
            if(a[j]==a[i] && duyet[j] == 0){
                check = 1;
                duyet[j] = 1;
                // break;
            }
        }
        if(check==1){
            printf("%d ", a[i]);
            empty = 1;
        }    
    }
    if(empty==0)    printf("0");
    return 0;
}