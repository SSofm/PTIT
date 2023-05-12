#include<stdio.h>
#include<string.h>
int main(){
    int t;  scanf("%d", &t);
    fflush(stdin);
    while(t--){
        char s[2000000];
        gets(s);
        int sl = 1;
        int even = 0;
        int odd = 0;
        for(int i = 0 ; i < strlen(s)-1; i++){
            if(s[i]==' ' && s[i+1]!=' ')    sl++;
        }
        for(int i = 0 ; i < strlen(s); i++){
            if((s[i+1] == ' ' || (i+1) == strlen(s)) && (s[i] - '0')%2==0)  even++;
            else if((s[i+1] == ' ' || (i+1) == strlen(s)) && (s[i] - '0')%2!=0) odd++;
        }
        if((sl%2==0 && even>odd) || (sl%2!=0 && odd > even))    printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}