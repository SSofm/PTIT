#include<stdio.h>
#include<string.h>
int compareString(char *s1, char *s2){
    if(strlen(s1)!=strlen(s2))  return 0;
    for(int i = 0 ; i< strlen(s1); i++) if(s1[i]!=s2[i])    return 0;
    return 1;
}
int main(){
    char s1[100];
    char s2[100];
    gets(s1);
    gets(s2);
    char *token;
    token = strtok(s1, " ");
    while(token!=NULL){
        if(strcmp(token, s2)) 
            printf("%s ", token);
        token = strtok(NULL, " ");
    }
    return 0;
}