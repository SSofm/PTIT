#include<stdio.h>
int main(){
    int t;  scanf("%d", &t);
    while(t--){
        int n;  scanf("%d", &n);
        int a[n];
        for(int i = 0 ; i < n; i++) scanf("%d", &a[i]);
        int dem = 0;
        for(int i = 0 ; i < n; i++){
                
            for(int j = i+1; j < n; j++){
                if(a[j] + a[i] ==  val) dem++;
            }
        }
        printf("%d\n", dem);
    }
    return 0;
}