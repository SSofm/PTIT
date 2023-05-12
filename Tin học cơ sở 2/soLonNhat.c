#include<stdio.h>
int main(){
    int t;  scanf("%d", &t);
    while(t--){
        int n;scanf("%d", &n);
        int a[n];
        int b[n];
        
        for(int i = 0 ;i < n; i++){
            scanf("%d", &a[i]);
            b[i] = a[i];
        }  
        for(int i = 0 ; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(a[j] < a[i]){
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
        printf("%d\n", a[n-1]);
        for(int i = 0 ; i < n; i++) if(b[i] == a[n-1])  printf("%d ", i);
        printf("\n");
    }
    return 0;
}