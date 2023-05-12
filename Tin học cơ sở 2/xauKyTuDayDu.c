#include<stdio.h>
#include<string.h>
int main(){
    int test[123];
    memset(test, 0, sizeof(test));  
    char s[50];
    scanf("%s", s);
    for(int i = 0 ; i < strlen(s); i++){
        test[s[i] - '0'] = 1;
    }
    int dem = 0;
    for(int i = 97 ; i <= 122; i++)    if(test[i] == 0)    dem++;
    printf("%d", dem);


    return 0;
}