#include<stdio.h>
int main(){
    int n;  scanf("%d", &n);
    int m = n;
    int res = 0;
    while(n--){
        int temp;
        scanf("%d", &temp);
        res += temp;
    }
    printf("%.3f", (float)res/m);
    return 0;
}