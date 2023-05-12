#include<stdio.h>
int isPrime(int n){
    if(n < 2)   return 0;
    for(int i = 2; i * i <= n; i++) if(n%i==0)  return 0;
    return 1;
}
int main(){
    int t;  scanf("%d", &t);
    for(int run = 1; run <= t; run++){
        int n;
        scanf("%d", &n);
        int a[n];
        int occ[n];
        for(int i = 0 ; i < n; i++) scanf("%d", &a[i]);
        for(int i = 0 ; i< n; i++){
            for(int j = i+1; j < n; j++){
                if(a[j] < a[i]){
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
        for(int i = 0 ; i< n; i++)  occ[i] = 0;
        printf("Test %d:\n", run);
        for(int i = 0 ; i < n; i++){
            
            if(isPrime(a[i]) && occ[i] == 0){
                int dem = 1;
                for(int j = i+1; j < n; j++){
                    if(occ[j] == 0 && a[j] == a[i]){
                        dem++;
                        occ[j] = 1;
                    }
                }
                printf("%d xuat hien %d lan\n", a[i], dem);
            }
        }

    }
    return 0;
}