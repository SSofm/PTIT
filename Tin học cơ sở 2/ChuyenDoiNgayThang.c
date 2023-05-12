#include<stdio.h>
int main(){
    int n;  scanf("%d", &n);
    int day = 0;
    int week = 0;
    int year = 0;
    do{
        if(n>=365){
            year++;
            n-=365;
        }else if(n>=7){
            week++;
            n-=7;
        }else{
            day+=n;
            break;
        }
        
    }while(n!=0);
    printf("%d %d %d", year, week, day);
    return 0;
}