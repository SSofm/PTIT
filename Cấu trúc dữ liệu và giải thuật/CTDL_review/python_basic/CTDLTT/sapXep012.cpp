#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int t; cin >> t;
    while(t--){
        int n;  cin >>n;
        int *a = new int[n];
        for(int i = 0 ; i < n; i++) cin >> a[i];
        sort(a, a+n);
        for(int i = 0 ; i < n;i++)  cout << a[i] << " ";
        cout << endl;
        delete a;
    }
    return 0;
}