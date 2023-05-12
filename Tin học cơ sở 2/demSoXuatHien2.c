#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    for(int run = 1; run <= t; run++)
    {
        int n;
        scanf("%d", &n);
        int a[n];
        int duyet[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            duyet[i] = 0;
        }
        printf("Test %d:\n", run);
        for (int i = 0; i < n; i++)
        {
            int dem = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (a[j] == a[i] && duyet[j] == 0)
                {
                    duyet[j] = 1;
                    dem++;
                }
            }
            if (duyet[i] == 0)
                printf("%d xuat hien %d lan\n", a[i], dem);
        }
    }

    return 0;
}