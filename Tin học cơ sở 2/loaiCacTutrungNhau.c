#include<stdio.h>
#include<string.h>
int NumberOfWord(char *s, int len){
    int res = 1;
    for(int i = 0 ; i< len; i++)    if(s[i] == ' ' && s[i+1]!=' ')  res++;
    return res;
}
int main(){
    char s[105];
    gets(s);
    int n = strlen(s);
    const int sl = NumberOfWord(s, n);
    char cont1[sl][105];
    char *token;
    token = strtok(s, " ");
    int run = 0;
    while(token!=NULL){
        strcpy(cont1[run++], token);
        token = strtok(NULL, " ");
    }
    int use[run];
    memset(use, 0, sizeof(use));
    for(int i = 0 ; i < run-1; i++){
        for(int j = i+1; j < run; j++){
            if(strcmp(cont1[i], cont1[j])==0)  use[j] = 1; 
        }
    }
    for(int i = 0 ; i < run; i++)   if(use[i]==0)   printf("%s ", cont1[i]);

    return 0;
}