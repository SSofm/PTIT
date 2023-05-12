#include<stdio.h>
#include<string.h>
int checkThuanNghich(char *s){
    for(int i = 0 ; i < strlen(s)/2; i++)   if(s[i] != s[strlen(s)-i-1]) return 0;
    return 1;
}
int checkEven(char *s){
    for(int i = 0 ; i < strlen(s); i++) if((s[i] - '0')%2!=0)   return 0;
    return 1;
}

int main(){
    int t;  scanf("%d", &t);
    while(t--){
        char s[500];
        scanf("%s", s);
        if(checkEven(s)&& checkThuanNghich(s) ) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}