#include<stdio.h>
#include<string.h>
int main(){
    int t;  scanf("%d", &t);
    fflush(stdin);
    while(t--){
        char s[50];
        gets(s);
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
        int vt = -1;
        for(int i = 0 ; i < n; i++){
            if(s[i] == ' '){
                vt=i;
                break;
            }
        }
        s[vt+1] -= 32;
        for(int i = vt+1; i < n; i++){
            if(s[i] == ' ') s[i+1] -= 32;
            printf("%c", s[i]);
        }
        printf(", ");
        for(i = 0 ; s[i]!=' '; i++) printf("%c", s[i]-32);
        printf("\n");
    }
    return 0;
}