#include<stdio.h>
int checkPerfectNum(int n){ 
    int sum  = 1;
    for(int i = 2; i *i <= n; i++){
        if(n%i==0){
            if(i*i!=n)  sum+= (i+n/i);
            else sum += i;
        }
    }
    if(sum==n && n!=1)  return 1;
    return 0;
}
int main(){
    int n;  scanf("%d", &n);
    for(int i = 1; i < n; i++)  if(checkPerfectNum(i)) printf("%d ", i);
    return 0;
}