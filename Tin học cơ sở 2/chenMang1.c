#include<stdio.h>
int main(){
    int n1, n2, vt;
    scanf("%d%d", &n1, &n2);

    int a[n1];
    int b[n2];
    
    for(int i = 0 ; i < n1; i++) scanf("%d", &a[i]);
    for(int i = 0 ; i < n2; i++) scanf("%d", &b[i]);
    scanf("%d", &vt);
    for(int i = 0 ; i < vt; i++)    printf("%d ", a[i]);
    for(int i = 0; i < n2; i++) printf("%d ", b[i]);
    for(int i = vt; i < n1; i++)    printf("%d ", a[i]);

    return 0;
}