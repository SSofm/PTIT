#include<bits/stdc++.h>
#define int long long
#define max 10
using namespace std;

void res(int *a, int n){
    cout << "[";
    for(int i = 0 ; i < n; i++){
        cout << a[i];
        if(i==n-1) break;
        cout << " ";
    } 
    cout << "] ";
}
void recur(int *a, int n){
    if(n < 1 )return; // dieu kien dung
    int f[n-1];
    for(int i = 0 ; i < n-1; i++){
        f[i] = a[i] + a[i+1];
    }
    recur(f, n-1);
    res(a, n);
}
int32_t main(){
    int t; cin >> t;
    while(t--){
        int a[max], n;
        cin >> n;
        for(int i = 0; i < n; i++)  cin >> a[i];
        recur(a, n);
        cout << endl;
    }
    return 0;
}