#include<bits/stdc++.h>
using namespace std;

struct soPhuc
{
    int thuc, ao;
};


int32_t main(){
    int t;  cin >> t;
    while(t--){
        soPhuc s1, s2;
        cin >> s1.thuc >> s1.ao >> s2.thuc >> s2.ao;

        int thuc = s1.thuc*s1.thuc + s2.thuc*s2.thuc - s1.ao * s1.ao - s2.ao *s2.ao + 2 * (s1.thuc * s2.thuc - s1.ao * s2.ao);
        int ao = 2*(s1.thuc*s1.ao + s2.thuc*s2.ao + s1.thuc * s2.ao + s1.ao*s2.thuc);
        if(ao > 0){
            cout << thuc << " + " << ao << "i" << endl;
        }else if(ao < 0){
            cout << thuc << " - " << ao*-1 << "i" << endl;   
        }

    }
    return 0;
}