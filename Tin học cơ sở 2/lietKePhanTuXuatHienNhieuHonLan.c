#include<stdio.h>
int main(){
    int n;  scanf("%d", &n);
    int a[n];
    int occ[n];
    for(int i = 0 ; i < n; i++){
        scanf("%d", &a[i]);
        occ[i] = 0;
    } 
    int dem = 0;
    int res[100];
    int run = 0;
    for(int i = 0 ;  i< n; i++){
        int check = 0;
        for(int j = i+1 ; j< n; j++){
            if(a[j] == a[i] && occ[j] == 0){
                check = 1;
                occ[j] = 1;
                break;
            }
        }
        if(check==1 && occ[i] == 0){
            dem++;
            res[run++] = a[i];
        }
    }
    printf("%d\n", dem);
    for(int i = 0 ; i < run; i++)   printf("%d ", res[i]);
    return 0;
}