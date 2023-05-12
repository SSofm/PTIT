#include<stdio.h>
#include<string.h>
int checkFull(char *s, int len){
    if(s[0] == '0')  return 2;
    int use[10];
    for(int i = 0 ;i < 10; i++) use[i] = 0;
    for(int i = 0 ; i< len; i++){
        if(s[i] >= '0' && s[i] <= '9') use[s[i] - '0'] = 1;
        else return 2;
    }
    for(int i = 0; i < 10; i++) if(use[i] == 0) return 0;
    return 1;
}
int main(){
    int t;  scanf("%d", &t);
    while(t--){
        char s[1005];
        scanf("%s", s);
        if(checkFull(s, strlen(s)) == 0)    printf("NO\n");
        else if(checkFull(s, strlen(s))==2) printf("INVALID\n");
        else if(checkFull(s, strlen(s)))    printf("YES\n");

    }
    return 0;
}