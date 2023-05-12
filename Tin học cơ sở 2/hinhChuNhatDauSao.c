#include<stdio.h>
int main(){
    int row, col;
    scanf("%d%d", &row, &col);
    for(int i = 1; i ,i <= col; i++){
        for(int j = 1; j <= row; j++){
            if(i >1 && i < col && j > 1 && j < row) printf(" ");
            else printf("*");
        }
        printf("\n");
    }
    return 0;
}