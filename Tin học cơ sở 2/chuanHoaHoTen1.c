#include<stdio.h>
#include<string.h>
int main(){
    int t;  scanf("%d", &t);
    fflush(stdin);
    while(t--){
        char s[80];
        // gets(s);
        fgets(s, sizeof(s), stdin);
        s[strlen(s)-1] = 0;
        int n = strlen(s);
        int i, j;
        for(i = 0 ; i < n; i++) if(s[i] >= 'A' && s[i] <= 'Z')  s[i] += 32;
        
        while(s[0] == ' '){
            for(j = 0 ; j < n; j++) s[j] = s[j+1];
            n--;
        }
        while(s[n-1] == ' '){
            s[n-1] = 0;
            n--;
        }
        j = 1;
        do{
            if(s[j] == ' ' && s[j+1] ==' '){
                for(i = j; i < n; i++)  s[i] = s[i+1];
                n--;
            }else j++;
        }while(j<=n-2);
        s[0] -= 32;
        for(int i = 0 ; i < n; i++){
            if(s[i] == ' ') s[i+1] -= 32;
            printf("%c", s[i]);
        }
        printf("\n%d\n", n);
    }
    return 0;
}