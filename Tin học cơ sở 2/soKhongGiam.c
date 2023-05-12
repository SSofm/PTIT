#include<stdio.h>
#include<string.h>
int check(char *s, int len){
    for(int i = 0 ; i <len-1; i++){
        if(s[i+1] < s[i])   return 0;
    }
    return 1;
}
int main(){
    int t;  scanf("%d", &t);
    while(t--){
        char s[20];
        scanf("%s", s);
        if(check(s, strlen(s))) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}