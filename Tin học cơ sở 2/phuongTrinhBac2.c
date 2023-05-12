#include<stdio.h>
#include<math.h>
int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    float delta = (b*b)-4*a*c;
    float r1 = (-b - sqrt(delta))/(2*a);
    float r2 = (-b + sqrt(delta))/(2*a);
    if(delta < 0)   printf("NO");
    else if(delta == 0) printf("%.2f", r1);
    else    printf("%.2f %.2f", r2, r1);
    return 0;
}