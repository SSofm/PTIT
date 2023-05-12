#include<stdio.h>
#include<string.h>
int checkCondi(char *s, int len){
    if((s[len-1] - '0')%2!=0)   return 0;
    for(int i = 0 ;i < len; i++)    if((s[i] - '0')%2!=0)   return 0;
    return 1;
}
int main(){
    int t;  scanf("%d", &t);
    while(t--){
        char s[20];
        scanf("%s", s);
        if(checkCondi(s, strlen(s)))    printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}