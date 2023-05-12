#include<stdio.h>
#include<string.h>
int tongChuSo(char *s, int len){
    int res = 0;
    for(int i = 0 ; i < len; i++)   res += (s[i] - '0');
    return (res%2!=0);
}
int checkThuanNghich(char *s, int len){
    for(int i = 0 ; i < len/2; i++) if(s[i]!=s[len-i-1])    return 0;
    return 1;
}
int checkDigit(char *s, int len){
    for(int i = 0 ; i < len; i++)   if((s[i] - '0')%2==0)   return 0;
    return 1;
}
int main(){
    int t;  scanf("%d", &t);
    while(t--){
        char s[20];
        scanf("%s", s);
        if(checkDigit(s, strlen(s)) && checkThuanNghich(s, strlen(s)) && tongChuSo(s, strlen(s)))   printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}