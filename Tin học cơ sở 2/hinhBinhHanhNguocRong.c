#include<stdio.h>
int main(){
    int row, col;
    scanf("%d%d", &row, &col);
    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col+i-1; j++ ){
            if(j < i)   printf("~");
            else if(j > i && j < (col+i-1) && i > 1 && i < row) printf(".");
            else printf("*");
        }
        printf("\n");
    }
    return 0;
}