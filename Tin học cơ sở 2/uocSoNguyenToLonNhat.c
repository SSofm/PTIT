#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

long long maxPrimeFactors(long long n)
{

    long long maxPrime = -1;
    while (n % 2 == 0) {
        maxPrime = 2;
        n >>= 1; // equivalent to n /= 2
    }
  
     while (n % 3 == 0) {
        maxPrime = 3;
        n=n/3;
    }
 
    for (int i = 5; i <= sqrt(n); i += 6) {
        while (n % i == 0) {
            maxPrime = i;
            n = n / i;
        }
      while (n % (i+2) == 0) {
            maxPrime = i+2;
            n = n / (i+2);
        }
    }
 
   
    if (n > 4)
        maxPrime = n;
 
    return maxPrime;
}
 
int main(){
    int t;  scanf("%d", &t);
    
    while(t--){
        long long n;  scanf("%lld", &n);
        printf("%lld\n", maxPrimeFactors(n));
        
    }
    return 0;
}