#include <iostream> 
#include <ctime> 

using namespace std;

class parabola
{
private:
    double a, b, c, ext;
public:
    parabola(double a, double b, double c) : a(a), b(b), c(c)
    {
        ext = (-b / a) * 0.5;
    }

    void extremum()
    {
        if (a < 0) {
            cout << "max:" << ext << endl;
        }
        else {
            cout << "min:" << ext << endl;
        }
    }

    void eq_show()
    {
        cout << "f(x) = " << a << "x^2 + " << b << "x + " << c << endl;
    }


    bool operator|| (parabola myPar);
    bool operator/ (parabola myPar);

    ~parabola()
    {}

};



bool parabola::operator|| (parabola myPar)
{
    if (a == myPar.a && b == myPar.b && c == myPar.c) return true;
    else return false;
}



bool parabola::operator/ (parabola myPar)
{
    double D = (b - myPar.b) * (b - myPar.b) - 4.0 * (a - myPar.a) * (c - myPar.c);
    if (D >= 0) return true;
    else return false;
}

int main()
{
    srand(time(0));
    int q = 25, o = -25;
    double a = o + rand() % ((q - o) + 1);
    double b = o + rand() % ((q - o) + 1);
    double c = o + rand() % ((q - o) + 1);

    parabola Die_gleichung1(a, b, c);
    Die_gleichung1.eq_show();
    Die_gleichung1.extremum();

    double d = o + rand() % ((q - o) + 1);
    double h = o + rand() % ((q - o) + 1);
    double n = o + rand() % ((q - o) + 1);

    parabola Die_gleichung2(d, h, n);

    Die_gleichung2.eq_show();
    Die_gleichung2.extremum();

    if (Die_gleichung1 || Die_gleichung2) { cout << "Paraboli ravni" << endl; }
    else { cout << "Paraboli peres" << endl; }
    return 0;
}