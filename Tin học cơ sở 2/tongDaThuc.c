#include<stdio.h>
#include<string.h>
struct polinomialForm
{
    int x, y;
};

int main(){
    int t;  scanf("%d", &t);
    fflush(stdin);
    while(t--){
        char s1[10005], s2[10005];
        gets(s1);
        gets(s2);
        struct polinomialForm a[10005];
        struct polinomialForm b[10005];
        int run = 0;
        int ar1[10005];
        int ar2[10005];
        int r1 = 0;
        int r2 = 0;
        for(int i = 0 ;i < strlen(s); i++){
            int temp = 0;
            int j = i;

            while(s[j] >= '0' && s[j] <= '9'){
                temp = temp *10 + (s[i] - '0');
                j++;
            }
            if(j!=i)    ar1[r1++] = temp;
            i = j;
        }
        for(int i = 0 ; i < r1-1; i+=2){
           
            a[run].x = ar1[i];
            a[run++].y = ar1[i+1];
          
        }  
        for(int i = 0 ;i < run; i++)    printf("%d %d\n", a[i].x, a[i].y);

        
    }
    return 0;
}