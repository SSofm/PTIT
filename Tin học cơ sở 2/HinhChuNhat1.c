#include <stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int row, col;
    scanf("%d%d", &row, &col);
    if (row == col)
    {
        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= col; j++)
            {
                if (j <= col - i + 1)
                    printf("%d", i + j - 1);
                else
                    printf("%d", row - j + 1);
            }
            printf("\n");
        }
    }
    else if (row < col)
    {
        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= col; j++)
            {
                if (j <= col - i + 1)
                    printf("%d", i + j - 1);
                else
                    printf("%d", col - j + 1);
            }
            printf("\n");
        }
    }
    else if (row > col)
    {
        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= col; j++)
            {
                if (j <= abs(col - i) + 1 && i <= col)
                    printf("%d", i + j - 1);
                else if(i > col && j == 1)  printf("%d", i);
                else printf("%d", abs(row - j) - 1);
            }
            printf("\n");
        }
    }

    return 0;
}