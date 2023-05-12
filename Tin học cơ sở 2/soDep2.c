#include<stdio.h>
#include<string.h>
int checkThuanNghich(char *s){
    for(int i = 0 ; i < strlen(s)/2; i++)   if(s[i] != s[strlen(s)-i-1]) return 0;
    return 1;
}
int checkStartEnd(char *s){
    return (s[0] == '8' && s[strlen(s)-1] == '8');
}
int tongChuSo(char *s){
    int res = 0;
    for(int i = 0 ;  i< strlen(s); i++) res += (s[i] - '0');
    return res;
}

int main(){
    int t;  scanf("%d", &t);
    while(t--){
        char s[500];
        scanf("%s", s);
        if(checkThuanNghich(s)&& checkStartEnd(s) && tongChuSo(s)%10==0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}