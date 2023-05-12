#include<stdio.h>
#include<string.h>
int main(){
    char s[100];
    gets(s);
    int chuCai = 0;
    int chuSo = 0;
    for(int i = 0 ; i < strlen(s); i++){
        if(s[i] >= 'A' && s[i] <= 'Z' || (s[i] >= 'a' && s[i] <= 'z'))  chuCai++;
        else if(s[i] >= '0' && s[i] <= '9') chuSo++;
    }
    printf("%d %d %d", chuCai, chuSo, strlen(s) - chuCai - chuSo);
    return 0;
}