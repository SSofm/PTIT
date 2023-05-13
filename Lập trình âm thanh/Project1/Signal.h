#include <bits/stdc++.h>
using namespace std;

class Signal{

private:
    vector<double> signal;
    int rootPos;

public:
    Signal()
    {
    }
    Signal(vector<double> signal_ex, int rootPos)
    {
        this->signal = signal_ex;
        this->rootPos = rootPos;
    }

    void setSignal(vector<double> signal_ex)
    {
        this->signal = signal_ex;
    }

    vector<double> getSignal()
    {
        return signal;
    }

    void setRootPos(int rootPos)
    {
        this->rootPos = rootPos;
    }

    int getRootPos()
    {
        return rootPos;
    }

    Signal reduceFrequency(int m)
    {
        /*

            Tang hay giam 1 thi van la chinh no

         */
        vector<double> temp = getSignal();
        int rootPos = getRootPos();
        int rootRes_pos = rootPos;
        vector<double> filterBe;
        vector<double> filterAf;
        int count_del = 0;
        for (int i = rootPos; i >= 0; i -= m){
            if (i != rootPos){
                filterBe.push_back(temp[i]);
                count_del++;
            }
        }
        rootRes_pos = count_del;
        reverse(filterBe.begin(), filterBe.end());   
        for (int i = rootPos; i < temp.size(); i += m)
            filterAf.push_back(temp[i]);

        vector<double> res(filterBe);
        res.insert(res.end(), filterAf.begin(), filterAf.end());

        return {res, rootRes_pos};
    }

    Signal increaseFrequency(int m)
    {
        vector<double> temp = getSignal();
        vector<double> res;
        int rootPos = getRootPos();
        int rootRes_pos = rootPos;
        for (int i = 0; i < temp.size() - 1; i++)
        {
            res.push_back(temp[i]);
            for (int j = 1; j < m; j++){
                if(i < rootPos) rootRes_pos++;
                res.push_back(0);
            }
                
        }
        res.push_back(temp[temp.size() - 1]);
        return {res, rootRes_pos};
    }

    Signal timeReverse()
    {
        /*
            x[n] --> x[-n]
            lat x[n] qua truc tung
         */
        vector<double> temp = getSignal();
        // vector<double> temp_verCopy{temp.begin(), temp.end()};
        
        int rootPos = getRootPos();
        reverse(temp.begin(), temp.end());
        vector<double> res{temp.begin(), temp.end()};
        int new_rootPos = temp.size()-rootPos-1;
        if(new_rootPos < temp.size()-new_rootPos-1){
            for(int i = 0 ; i < (temp.size()-new_rootPos-1) - new_rootPos; i++) res.insert(res.begin(), 0);
        }else if(new_rootPos > temp.size()-new_rootPos-1){
            for(int i = 0 ; i < new_rootPos - (temp.size()-new_rootPos-1); i++) res.push_back(0);
        }
        return {res, new_rootPos};
    }

    Signal timeTranslation(int m)
    {

        /*
            x[n-1] => m = 1 => tre mot mau thi dich sang phai mot mau
            va nguoc lai
            suy ra m duong thi insert, am thi push_back
         */

        vector<double> temp = getSignal();
        vector<double> res(temp.size(), 0);
        if (m > 0)
            for (int i = 0; i < m; i++)
                temp.insert(temp.begin(), 0);
        else
            for (int i = 0; i < abs(m); i++)
                temp.push_back(0);

        if (m > 0)
        {
            for (int i = 0; i < temp.size(); i++)
            {
                if (i >= res.size() && temp[i] != 0)
                    res.push_back(temp[i]);
                else if (i < res.size())
                    res[i] = temp[i];
            }
        }
        else
        {
            int run = 0;
            for (int i = abs(m); i < temp.size(); i++)
                res[run++] = temp[i];
        }
        return {res, getRootPos()};
    }

    Signal MultiWithConstant(double c)
    {
        vector<double> temp = getSignal();

        for (auto &x : temp){
            if(x!=0)    
                x *= c;
        }
            
        return {temp, getRootPos()};
    }

    Signal SumSignal(vector<double> signal_ex, int rootPosition)
    {
        vector<double> itsSignal = getSignal();
        int itsRoot = getRootPos();
        int rootRes = itsRoot;
        vector<double> res;


        vector<double> signalFirstBe{itsSignal.begin(), itsSignal.begin() + itsRoot};
        int d1 = signalFirstBe.size();

        vector<double> signalFirstAf{itsSignal.begin() + itsRoot, itsSignal.end()};
        int d2 = signalFirstAf.size();

        vector<double> signalSecondBe{signal_ex.begin(), signal_ex.begin() + rootPosition};
        int d3 = signalSecondBe.size();

        vector<double> signalSecondAf{signal_ex.begin() + rootPosition, signal_ex.end()};
        int d4 = signalSecondAf.size();

        int dis1 = abs(d1 - d3);

        if (signalFirstBe.size() < signalSecondBe.size())
        {
            for (int i = 0; i < dis1; i++){
                signalFirstBe.insert(signalFirstBe.begin(), 0);
                rootRes++;
            }
                
        }
        else if (signalFirstBe.size() > signalSecondBe.size())
        {
            for (int i = 0; i < dis1; i++)
                signalSecondBe.insert(signalSecondBe.begin(), 0);
        }

        int dis2 = abs(d2 - d4);

        if (signalFirstAf.size() < signalSecondAf.size())
        {
            for (int i = 0; i < dis2; i++)
                signalFirstAf.push_back(0);
        }
        else if (signalFirstAf.size() > signalSecondAf.size())
        {
            for (int i = 0; i < dis2; i++)
                signalSecondAf.push_back(0);
        }

        vector<double> total1(signalFirstBe);
        total1.insert(total1.end(), signalFirstAf.begin(), signalFirstAf.end());
        vector<double> total2(signalSecondBe);
        total2.insert(total2.end(), signalSecondAf.begin(), signalSecondAf.end());
        
        for (int i = 0; i < total1.size(); i++) res.push_back(total1[i] + total2[i]);
            
        return {res, rootRes};
    }

    Signal DiffSignal(vector<double> signal_ex, int rootPosition)
    {
        vector<double> itsSignal = getSignal();
        int itsRoot = getRootPos();
        int rootRes = itsRoot;
        vector<double> res;
        vector<double> signalFirstBe{itsSignal.begin(), itsSignal.begin() + itsRoot};
        int d1 = signalFirstBe.size();

        vector<double> signalFirstAf{itsSignal.begin() + itsRoot, itsSignal.end()};
        int d2 = signalFirstAf.size();

        vector<double> signalSecondBe{signal_ex.begin(), signal_ex.begin() + rootPosition};
        int d3 = signalSecondBe.size();

        vector<double> signalSecondAf{signal_ex.begin() + rootPosition, signal_ex.end()};
        int d4 = signalSecondAf.size();

        int dis1 = abs(d1 - d3);

        if (signalFirstBe.size() < signalSecondBe.size())
        {
            for (int i = 0; i < dis1; i++){
                signalFirstBe.insert(signalFirstBe.begin(), 0);
                rootRes++;
            }
                
        }
        else if (signalFirstBe.size() > signalSecondBe.size())
        {
            for (int i = 0; i < dis1; i++)
                signalSecondBe.insert(signalSecondBe.begin(), 0);
        }

        int dis2 = abs(d2 - d4);

        if (signalFirstAf.size() < signalSecondAf.size())
        {
            for (int i = 0; i < dis2; i++)
                signalFirstAf.push_back(0);
        }
        else if (signalFirstAf.size() > signalSecondAf.size())
        {
            for (int i = 0; i < dis2; i++)
                signalSecondAf.push_back(0);
        }

        vector<double> total1(signalFirstBe);
        total1.insert(total1.end(), signalFirstAf.begin(), signalFirstAf.end());
        vector<double> total2(signalSecondBe);
        total2.insert(total2.end(), signalSecondAf.begin(), signalSecondAf.end());
        
        for (int i = 0; i < total1.size(); i++)
            res.push_back(total1[i] - total2[i]);
        return {res, rootRes};
    }

    Signal MultiSignal(vector<double> signal_ex, int rootPosition)
    {
        vector<double> itsSignal = getSignal();
        int itsRoot = getRootPos();
        int rootRes = itsRoot;
        vector<double> res;


        vector<double> signalFirstBe{itsSignal.begin(), itsSignal.begin() + itsRoot};
        int d1 = signalFirstBe.size();

        vector<double> signalFirstAf{itsSignal.begin() + itsRoot, itsSignal.end()};
        int d2 = signalFirstAf.size();

        vector<double> signalSecondBe{signal_ex.begin(), signal_ex.begin() + rootPosition};
        int d3 = signalSecondBe.size();

        vector<double> signalSecondAf{signal_ex.begin() + rootPosition, signal_ex.end()};
        int d4 = signalSecondAf.size();

        int dis1 = abs(d1 - d3);

        if (signalFirstBe.size() < signalSecondBe.size())
        {
            for (int i = 0; i < dis1; i++){
                signalFirstBe.insert(signalFirstBe.begin(), 0);
                rootRes++;
            }
                
        }
        else if (signalFirstBe.size() > signalSecondBe.size())
        {
            for (int i = 0; i < dis1; i++)
                signalSecondBe.insert(signalSecondBe.begin(), 0);
        }

        int dis2 = abs(d2 - d4);

        if (signalFirstAf.size() < signalSecondAf.size())
        {
            for (int i = 0; i < dis2; i++)
                signalFirstAf.push_back(0);
        }
        else if (signalFirstAf.size() > signalSecondAf.size())
        {
            for (int i = 0; i < dis2; i++)
                signalSecondAf.push_back(0);
        }

        vector<double> total1(signalFirstBe);
        total1.insert(total1.end(), signalFirstAf.begin(), signalFirstAf.end());
        vector<double> total2(signalSecondBe);
        total2.insert(total2.end(), signalSecondAf.begin(), signalSecondAf.end());
        
        for (int i = 0; i < total1.size(); i++)
            res.push_back(total1[i] * total2[i]);
        return {res, rootRes};
    }

    Signal signalConvolution(vector<double> signal_sample, int rootPos_sample)
    {
        vector<double> itsSignal = getSignal();
        int itsRoot = getRootPos();
        int row = itsSignal.size();
        int col = signal_sample.size();


        // xuat cac phan tu nam phia tren duong cheo chinh

        vector<vector<double>> matrix;
        for (int i = 0; i < row; i++)
        {
            vector<double> temp;
            for (int j = 0; j < col; j++)
            {
                temp.push_back(itsSignal[i] * signal_sample[j]);
            }
            matrix.push_back(temp);
        }

        // cout << "Cac phan tu nam phia tren duong cheo chinh la: " << endl;

        vector<double> res;
        vector<vector<vector<int>>> checkRoot;
        int rootRes = 0;

        for (int i = 0; i < row; i++)
        {
            int temp = i;
            double sum = 0;
            vector<vector<int>> temp_checkR;
            for (int j = 0; j <= i; j++)
            {
                temp_checkR.push_back({temp, j});
                sum += matrix[temp][j];
                temp--;
            }
            res.push_back(sum);
            checkRoot.push_back(temp_checkR);
        }

        for (int i = 1; i < col; i++)
        {
            int temp = row-1;
            int sum = 0;
            vector<vector<int>> temp_checkR;
            for (int j = i; j < col; j++)
            {
                temp_checkR.push_back({temp, j});
                sum += matrix[temp][j];
                temp--;
            }
            checkRoot.push_back(temp_checkR);
            res.push_back(sum);
        }
        // for(auto x : res)   cout << x << ' ';
        for (int i = 0; i < checkRoot.size(); i++)
        {
            bool flag = true;
            for (int j = 0; j < checkRoot[i].size(); j++)
            {
                if(itsRoot == checkRoot[i][j][0] && rootPos_sample == checkRoot[i][j][1]){
                    rootRes = i;
                    flag = false;
                    break;
                }
            }
            if(!flag)   break;
        }
        return {res, rootRes};
    }

    Signal CrossCorrelation(vector<double> signal_sample, int rootPos_sample)
    {
        vector<double> itsSignal = getSignal();

        Signal s{{0, 0, 1, 1, 0, 0}, 2};
        Signal secondSign = s.timeReverse();
       
        vector<double> signal_sample_ver2 = secondSign.getSignal();
       
        int rootPos_sample_ver2 = secondSign.getRootPos();
       
        int itsRoot = getRootPos();
        int row = itsSignal.size();
        int col = signal_sample_ver2.size();


        // xuat cac phan tu nam phia tren duong cheo chinh

        vector<vector<double>> matrix;
        for (int i = 0; i < row; i++)
        {
            vector<double> temp;
            for (int j = 0; j < col; j++)
            {
                temp.push_back(itsSignal[i] * signal_sample_ver2[j]);
            }
            matrix.push_back(temp);
        }

        // cout << "Cac phan tu nam phia tren duong cheo chinh la: " << endl;

        vector<double> res;
        vector<vector<vector<int>>> checkRoot;
        int rootRes = 0;

        for (int i = 0; i < row; i++)
        {
            int temp = i;
            double sum = 0;
            vector<vector<int>> temp_checkR;
            for (int j = 0; j <= i; j++)
            {
                temp_checkR.push_back({temp, j});
                sum += matrix[temp][j];
                temp--;
            }
            res.push_back(sum);
            checkRoot.push_back(temp_checkR);
        }

        for (int i = 1; i < col; i++)
        {
            int temp = row-1;
            int sum = 0;
            vector<vector<int>> temp_checkR;
            for (int j = i; j < col; j++)
            {
                temp_checkR.push_back({temp, j});
                sum += matrix[temp][j];
                temp--;
            }
            checkRoot.push_back(temp_checkR);
            res.push_back(sum);
        }
        // for(auto x : res)   cout << x << ' ';
        for (int i = 0; i < checkRoot.size(); i++)
        {
            bool flag = true;
            for (int j = 0; j < checkRoot[i].size(); j++)
            {
                if(itsRoot == checkRoot[i][j][0] && rootPos_sample_ver2 == checkRoot[i][j][1]){
                    rootRes = i;
                    flag = false;
                    break;
                }
            }
            if(!flag)   break;
        }
        return {res, rootRes};
    }
};
