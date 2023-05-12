#include<stdio.h>
int stop(int *a, int n){
    for(int i = 0; i < n-1; i++)  if(a[i+1] < a[i])   return 0;
    return 1;
}
int main(){
    int n;  scanf("%d", &n);
    int a[n];
    for(int i = 0 ; i< n; i++)  scanf("%d", &a[i]);
    int step = 1;
    for(int i = 0 ; i < n-1;i++){
        printf("Buoc %d: ", i+1);
        for(int j = 0; j < n-i-1; j++){
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
         
        for(int i = 0; i < n; i++)  printf("%d ", a[i]);
        printf("\n");
        if(stop(a, n))  break;
       
    }
        
      
   
    return 0;
}