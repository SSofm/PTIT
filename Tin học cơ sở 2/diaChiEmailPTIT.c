#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char s[50];

    gets(s);
    int n = strlen(s);
    for(int i = 0 ; i < n; i++) if(s[i] >= 'A' && s[i] <= 'Z')  s[i] += 32;
    int i, j;
    // xoa dau cach o dau
    while(s[0] == ' '){
        for(j = 0 ; j < n; j++)    s[j] = s[j+1];
        n--;
    }
    // xua dau cach o cuoi
    while(s[n-1] == ' '){
        s[n-1] = 0;
        n--;
    }
    // xoa dau cach o giua
    j = 1;
    do{
        if(s[j] == ' ' && s[j+1] == ' '){
            for(i = j; i < n; i++)  s[i] = s[i+1];
            n--;
        }else j++;
    }while(j<= n-2);
    char res[50];
    memset(res, ' ', sizeof(res));
    int vt = -1;
    for(int i = n; i >= 0; i--) if(s[i] == ' '){
        vt = i;
        break;
    }
    res[0] = s[0];
    int run = 1;
    for(int i = 0 ;  i< vt; i++){
        if(s[i] == ' '){
            res[run++] = s[i+1];
        }
    }
    for(int i = vt+1;i < n; i++)   res[run++] = s[i];
    for(int i = 0 ; i< run; i++) printf("%c", res[i]);
    printf("@ptit.edu.vn");
    return 0;
}