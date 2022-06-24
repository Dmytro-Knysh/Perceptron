#include <iostream>
#include <iomanip>
using namespace std;
class lw_1
{
private:
    const int truth_table[8][4] = { {0,0,0,1},{0,0,1,1},{0,1,0,1},{0,1,1,1},{1,0,0,0},{1,0,1,1},{1,1,0,1},{1,1,1,1} };
    long double teta = 0;
    short x1, x2, x3,y,t;
    const double eta = 0.7;// 0.1 0.5 0.7
    long double w1 = 0 + double(rand()) / RAND_MAX * (1 - 0);
    long double w2 =  0 + double(rand()) / RAND_MAX * (1 - 0);
    long double w3 = 0 + double(rand()) / RAND_MAX * (1 - 0);
    long double a,nty,delta_w1 = 0,delta_w2 = 0,delta_w3 = 0,delta_teta = 0;
    double found_y(double a, double teta)
    {
        if (a >= teta)
        {
            y = 1;
            return y;
        }
        else
        {
            y = 0;
            return y;
        }
    }
public:
    void result()
    {
        cout << setw(3) << " w1 " << setw(3) << "    w2 " << setw(3) << "   w3 " << setw(3) << " teta " << setw(2) << "  x1 " << setw(2) << "x2 " << setw(2) << "x3 " << setw(3) << "  a " << setw(2) << "   Y " << setw(2) << " T " << setw(6) << " n(T-Y) " << setw(8) << "delta_w1 " << setw(8) << " delta_w2 " << setw(8) << "  delta_w3" << setw(8) << " delta_teta" << endl;
        bool flag = false;
        int correct_result = 0;
        while (!flag)
        {
            for (int i = 0; i < 8; i++)
            {
                w1 += delta_w1;
                w2 += delta_w2;
                w3 += delta_w3;
                teta += delta_teta;
                x1 = truth_table[i][0];
                x2 = truth_table[i][1];
                x3 = truth_table[i][2];
                a = x1 * w1 + x2 * w2 + x3 * w3;
                t = truth_table[i][3];
                y = found_y(a, teta);
                nty = eta * (t - y);
                delta_w1 = nty * x1;
                delta_w2 = nty * x2;
                delta_w3 = nty * x3;
                delta_teta = nty * teta;
                if (y == t)
                {
                    correct_result++;
                }
                cout << setw(3)<< fixed<<setprecision(3)<< w1 <<" "<< setw(3)<<fixed<<setprecision(3) << w2<<" "<< setw(3)<<fixed<<setprecision(3) << w3<< " " << setw(3)<<fixed<<setprecision(3) << teta<< " " << setw(2) << x1<< " " << setw(2) << x2 << " " << setw(2) << x3 <<"  " << setw(3)<<fixed<<setprecision(3) << a<<" " << setw(2) << y << " " << setw(2) << t << " " << setw(6)<<fixed<<setprecision(3) << nty <<" "<< setw(8)<<fixed<<setprecision(3) << delta_w1 << " " << setw(8)<<fixed<<setprecision(3) << delta_w2 << " " << setw(8)<<fixed<<setprecision(3) << delta_w3 << " " << setw(8)<<fixed<<setprecision(3) << delta_teta << endl;
                
            }
            cout << endl;
            if (correct_result == 8)
            {
                flag = true;
            }
            else
            {
                correct_result = 0;
                delta_teta = 0;
                delta_w1 = 0;
                delta_w2 = 0;
                delta_w3 = 0;
            }
        }
    }
};

int main()
{
   lw_1 a;
   a.result();
}
