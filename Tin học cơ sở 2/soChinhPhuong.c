#include<stdio.h>
#include<math.h>

int isPerfectSquare(int n){
    int s = sqrt(n);
    return (s*s) == n;
}
int main(){
    int t;  scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        if(isPerfectSquare(n))  printf("YES\n");
        else printf("NO\n");
    }
}