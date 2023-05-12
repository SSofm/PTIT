#include <stdio.h>
long long gdc(long long a, long long b)
{
    if (a == 0 || b == 0)
        return a + b;
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}
int main()
{
    int t;
    
    scanf("%d", &t);
    while (t--)
    {
        long long a, b;
        scanf("%lld%lld", &a, &b);
        printf("%lld %lld", a * b / gdc(a, b), gdc(a, b));
        printf("\n");
    }
}