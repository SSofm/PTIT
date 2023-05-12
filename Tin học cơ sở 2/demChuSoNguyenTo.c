#include<stdio.h>
#include<string.h>
int isPrime(int n){
    if(n<2) return 0;
    for(int i = 2; i * i <= n; i++) if(n%i==0)  return 0;
    return 1;
}
void countPrimeDigit(char *s, int len){
    int occ[len];
    for(int i = 0 ; i < len; i++)   occ[i] = 0;
    for(int i = 0 ; i < len; i++){
        if(isPrime(s[i] - '0') && occ[i] == 0){
            int dem = 1;
            for(int j = i+1; j < len; j++){
                if(s[j] == s[i]){
                    dem++;
                    occ[j] = 1;
                }
            }
            printf("%c %d\n", s[i], dem);
        }

    }   
    
}
int main(){
    char s[20];
    scanf("%s", s);
    countPrimeDigit(s, strlen(s));
    return 0;
}