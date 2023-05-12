#include<stdio.h>
void sortArr(int *a, int n){
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1; j < n; j++){
            if(a[j] < a[i]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
int main(){
    int n;  scanf("%d", &n);
    int a[n];
    int even = 0;
    int odd = 0;
    for(int i = 0 ; i < n; i++){
        scanf("%d", &a[i]);
        if(a[i]%2==0)   even++;
        else odd++;
    } 
    
    int b[even];
    int run1 = 0;
    int run2 = 0;
    for(int i = 0 ; i < n; i++) if(a[i]%2==0)   b[run1++] = a[i];
    sortArr(b, even);
    int c[odd];
    for(int i = 0 ; i < n; i++) if(a[i]%2!=0)   c[run2++] = a[i];
    sortArr(c, odd);
    for(int i = 0 ; i < even; i++)  printf("%d ", b[i]);
    for(int i = 0 ; i < odd; i++)  printf("%d ", c[i]);
    
    return 0;
}