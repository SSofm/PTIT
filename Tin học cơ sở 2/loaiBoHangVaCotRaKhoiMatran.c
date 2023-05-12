#include<stdio.h>
int main(){
    int t;  scanf("%d", &t);
    for(int run = 1; run <= t; run++){
        int row, col;   scanf("%d%d", &row, &col);
        int a[row][col];
        for(int i = 0 ; i < row; i++){
            for(int j = 0 ; j < col; j++)   scanf("%d", &a[i][j]);
        }
        printf("Test %d:\n", run);
        for(int i = 0 ; i< row; i++){
            for(int j = 0 ; j< col ;j++){
                if(i!=0 && j !=0)   printf("%d ", a[i][j]);
            }
            if(i!=0)
            printf("\n");
        }
        
    }
    return 0;
}