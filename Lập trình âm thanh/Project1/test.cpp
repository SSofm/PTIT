#include <bits/stdc++.h>
#include "Signal.h"
using namespace std;
void test(vector<double> signalFirst, vector<double> signalSecond, int rootPosition1, int rootPosition2){
      vector<double> signalFirstBe{signalFirst.begin(), signalFirst.begin()+rootPosition1};
            vector<double> signalFirstAf{signalFirst.begin()+rootPosition1, signalFirst.end()};
            vector<double> signalSecondBe{signalSecond.begin(), signalSecond.begin()+rootPosition2};
            vector<double> signalSecondAf{signalSecond.begin()+rootPosition2, signalSecond.end()};
           
            if(signalFirstBe.size()<signalSecondBe.size()){
                for(int i = 0 ; i < abs(signalFirstBe.size()-signalSecondBe.size()); i++)    signalFirstBe.insert(signalFirstBe.begin(), 0);
            }else if(signalFirstBe.size()>signalSecondBe.size()){
                for(int i = 0 ; i < abs(signalFirstBe.size()-signalSecondBe.size()); i++)    signalSecondBe.insert(signalFirstBe.begin(), 0);
            }
            int dis1 = abs(signalFirstAf.size()-signalSecondAf.size());
            if(signalFirstAf.size()<signalSecondAf.size()){
                for(int i = 0 ; i < dis1; i++)    signalFirstAf.push_back(0);
            }else if(signalFirstAf.size()>signalSecondAf.size()){
                for(int i = 0 ; i < dis1; i++)    signalSecondAf.push_back(0); 
            }


            // for(auto x : signalFirstBe) cout << x << ' ';
            // for(auto x : signalFirstAf) cout << x << ' ';
            cout << endl;

            for(auto x : signalSecondBe) cout << x << ' ';
            for(auto x : signalSecondAf) cout << x << ' ';
}
int main()
{
    // vector<int> a{1, 2, 3, 4, 5};
    
    // // fill(a.begin(), a.begin()+3, 0);
    // vector<int> b{a.begin(), a.begin()+2};
    // vector<int> c{a.begin()+2, a.end()};
    // for(int i = 0 ; i < 2; i++) a.insert(a.begin(), 0);
    // for(auto x : a) cout << x << ' ';
    // cout << endl;
    // for(auto x : b) cout << x << ' ';
    // cout << endl;
    // for(auto x : c) cout << x << ' ';

    // cout < endl;
    // cout << abs(2-3);

    // Signal ob1({0, 0, 1, 0, 0.5, 0.25, 0}, 2);
    // Signal ob1({0, 1, 2, 1, 0}, 0);
    Signal ob1({0, 0, 1, 1, 1, 0, 0}, 2);
    // Signal ob1({0, 0, 1, 1, 0, 0}, 2);
    // Signal ob1({2, -1, 5}, 0);
    // Signal ob1({1, 3, 4}, 1);
    // Signal ob1({0, 1, 2, 1, 0}, 4);
    // {0, 0, 1, 1, 0.5, 1, 0, 1, 0}
    // {0, 0, 0, 1, 0.5, 0.25, 0, 0}
    // vector<double> b{0, 1, 0.5, 0.25, 0, 1, 0};
    // vector<double> res = ob1.SumSignal(b, 1);
    // vector<double> res3 = ob1.DiffSignal(b, 1);
    // vector<double> res2 = ob1.MultiSignal(b, 1);
    // for(auto x : res2)   cout << x << " ";
    // cout << endl;
    // for(auto x : res)   cout << x << " ";
    // cout << endl;
    // for(auto x : res3)   cout << x << " ";
    // cout << endl;
    // vector<double> res4 = ob1.MultiWithConstant(2);
    // for(auto x : res4)  cout << x << ' ';

    // vector<double> res5 = ob1.timeTranslation(-2);
    // for(auto x : res5)  cout << x << ' ';
    // cout << endl;
    // vector<double> res6 = ob1.timeReverse();
    // vector<double> res6 = ob1.reduceFrequency(3);
    // vector<double> res6 = ob1.increaseFrequency(2);
    // vector<double> res7 = ob1.signalConvolution({2, -1, 5}, 0);
    // vector<double> res6 = ob1.getSignal();
    // for(auto x : res7)  cout << x << ' ';
    // cout << endl;
    
    // Signal temp = ob1.signalConvolution({1, 3, 4}, 1);
    // cout << "Vi tri root la: " << temp.getRootPos() << endl;
    // for(auto x : temp.getSignal())  cout << x << ' ';

    // Signal temp = ob1.CrossCorrelation({0, 0, 1, 1, 0, 0}, 2);
    // cout << "Vi tri root la: " << temp.getRootPos() << endl;
    // for(auto x : temp.getSignal())  cout << x << ' ';


    // Signal temp{{0, 0, 1, 1, 0, 0}, 2};
    // Signal test = temp.timeReverse();
    // cout << "Vi tri root Moi la: " << test.getRootPos() << endl;
    // for(auto x : test.getSignal())  cout << x << ' ';
    
    // test(a, b, 2, 3);
    // Signal s2 = ob1.CrossCorrelation({0, 0, 1, 1, 0, 0}, 2);
    // Signal s2 = ob1.timeTranslation(1);
    // Signal s2 = ob1.increaseFrequency(2);
    // Signal s2 = ob1.signalConvolution({2, -1, 5}, 0);
    Signal s2 = ob1.CrossCorrelation({0, 0, 1, 1, 0, 0}, 2);
    for(auto x : s2.getSignal())    cout << x << " ";
    cout << endl;
    cout << s2.getRootPos() << endl;
    return 0;
}
