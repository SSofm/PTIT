#include<stdio.h>
#include<string.h>
int isIsometrix(char *s, int len){
    for(int i = 0 ; i < len/2; i++) if(s[i] != s[len-i-1])  return 0;
    return 1;
}
int isPrime(int n){
    if(n<2) return 0;
    for(int i = 2; i *i <= n; i++)  if(n%i==0)  return 0;
    return 1;
}
int isStringPrime(char *s, int len){
    for(int i = 0 ; i < len; i++)   if(!isPrime(s[i] - '0'))    return 0;
    return 1;
}
int main(){
    int t;  scanf("%d", &t);
    while(t--){
        char s[505];
        scanf("%s", s);
        if(isStringPrime(s, strlen(s)) && isIsometrix(s, strlen(s)))    printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}