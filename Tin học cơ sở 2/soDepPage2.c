#include<stdio.h>
#include<string.h>
int checkDC(char *s, int len){
    int d = s[0] - '0';
    int c = s[len-1] - '0';
    return ((d == 2*c) || (c==2*d));
}
int checkThuanNghich(char *s, int len){
    for(int i = 0; i < len/2; i++){
        if(i!=0 && i != len-1){
            if(s[i] != s[len-i-1])  return 0;
        }
    }    
    return 1;
}
int main(){
    int t;  scanf("%d", &t);
    while(t--){
        char s[20];
        scanf("%s", s);
        if(checkDC(s, strlen(s))&&checkThuanNghich(s, strlen(s)))  printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}