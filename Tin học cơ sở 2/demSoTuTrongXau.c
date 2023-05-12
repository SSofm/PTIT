#include<stdio.h>
#include<string.h>

int main(){
    int t;  scanf("%d", &t);
    fflush(stdin);
    while(t--){
        char s[205];
        gets(s);
        int i, j;
        int n = strlen(s);
        while(s[0] == ' '){
            for(j = 0 ; j< n; j++)  s[j] = s[j+1];
            n--;
        }
        int dem = 1;
        while(s[n-1] == ' '){
            s[n-1] = 0;
            n--;
        }
        j = 1;
        do{
            if(s[j] == ' ' && s[j+1] == ' '){
                for(i = j ; i < n; i++) s[i] = s[i+1];
                n--;
            }else j++;
        }while(j<=n-2);
        for(int i = 0 ; i < n; i++) if(s[i] == ' '&& s[i+1]!=' ')   dem++;
        printf("%d\n", dem);
    }
    return 0;
}