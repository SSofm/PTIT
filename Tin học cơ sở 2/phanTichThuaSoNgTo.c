#include<stdio.h>
#include<math.h>
int isPrime(int n){
    if(n<2) return 0;
    for(int i =2; i *i <= n; i++)   if(n%i==0)  return 0;
    return 1;
}
int main(){
    int t;  scanf("%d", &t);
    while(t--){
        int n;  scanf("%d", &n);
        printf("%d = ", n);
        for(int i = 2; i <= n; i++){
            if(isPrime(i)){
                int dem = 0;
                while(n%i==0){
                    dem++;
                    n/=i;
                }
                if(dem>=1){
                    printf("%d^%d", i, dem);
                    if(n>i) printf(" * ");
                }
                    
            }
            
        }
        printf("\n");
    }
    return 0;
}