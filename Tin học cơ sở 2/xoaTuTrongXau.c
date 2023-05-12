#include <stdio.h>
#include <string.h>
int compareString(char *s1, int len1, char *s2, int len2){
    if(len1!=len2)  return 0;
     
    for(int i = 0 ; i < len1; i++){
        int temp1 = s1[i];
        int temp2 = s2[i];
        if(temp1>='A' && temp1<= 'Z')   temp1 += 32;
        if(temp2>='A' && temp2<= 'Z')   temp2 += 32;
        if(temp1!=temp2)    return 0;

    }
    return 1;
}
int main()
{
    int t;
    scanf("%d", &t);
    // fflush(stdin);
    for(int run = 1; run <= t; run++)
    {
        char s1[205];
        char s2[100];
        fflush(stdin);
        gets(s1); 
        
        scanf("%s", s2);
        char *token;
        token = strtok(s1, " ");
        printf("Test %d: ", run);
        while (token != NULL)
        {
            if (compareString(token, strlen(token), s2, strlen(s2))==0)
                printf("%s ", token);
            token = strtok(NULL, " ");
        }
        printf("\n");
    }

    return 0;
}