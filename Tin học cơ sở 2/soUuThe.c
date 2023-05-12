#include<stdio.h>
#include<string.h>
int check(char *s, int len){
    int even = 0;
    int odd = 0;
    for(int i = 0; i < len; i++){
        if(s[i] >= '0' && s[i] <= '9'){
            if((s[i] - '0')%2==0)   even++;
            else odd++;
        }else return 2;
        
    }
    if(even==odd)   return 2;
    else if((len%2==0 && even>odd)||(len%2!=0 && odd>even)) return 1;
    else return 0;
}
int main(){
    int t;  scanf("%d", &t);
    while(t--){
        char s[1005];
        scanf("%s", s);
        if(check(s, strlen(s)) == 1)    printf("YES\n");
        else if(check(s, strlen(s)) == 0)   printf("NO\n");
        else if(check(s, strlen(s)) == 2)   printf("INVALID\n");   
    }
    return 0;
}