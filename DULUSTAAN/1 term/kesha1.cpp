#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int fac(int n) 
{
    int s = 1;
    for (int i = 1; i <= n; i++)
    {
        s *= i;
    }
    return s;
}

int main()
{
/*    //====1====
    double a = 0, b = 0, p = 0, d = 0;
    cout << "a, b" << endl;
    cin >> a >> b;
    
    if ((a < 0) and (b < 0)) return 0;
    
    p = a*2 + b*2;
    d = pow(a*a + b*b, 0.5);
    
    cout << a << " " << b;
    return 0;
    
    //====2====
    int n = 0, q = 0, o = 0, a = 0, b = 0, c = 0;
    cout << "XXX" << endl;
    cin >> n;
    if ((n > 99) and (n < 1000))
    {
        a = n / 100;
        b = (n / 10) % 10;
        c = n % 10;
        cout << a*a + b*b + c*c << " " << c,b,a;
    }
    else return 0;
    return 0;
    
    //====3====
    int a = 0;
    cout << "a = ";
    cin >> a;
    if (a > 0)
    {
        if ((a > 99) and (a < 1000)) cout << "exactly";
        else if (a < 100) cout << "less";
        else cout << "more";
    }*/
    
    //====4====
    // double a = 0, b = 0, x, xq;
    // cout << "a and b for ax^3 + bx = 0" << endl;
    // cout << "a = ";
    // cin >> a;
    // cout << "b = ";
    // cin >> b;
    // cout << a << "x^3 + " << b << "x = 0" << endl;
    // cout << "output in brackets x" << endl;
    // cout << endl;
    // cout << "x(" << a << "x^2 + " << b << ") = 0" << endl;
    // cout << "x1 = 0 " << " ||  ";
    // cout << a << "x^2 + " << b << " = 0" << endl;
    // cout << "x^2 = " << b << "/" << a << endl;
    // if ((a == 0) and (b == 0))
    // {
    //     cout << "==============" << endl;
    //     cout << "ANSWER " << "x = 0";
    //     return 0;
    // }
    // if (a == 0)
    // {
    //     cout << "==============" << endl;
    //     cout << "ANSWER " << "x1 = 0 and " << -b << "/" << a << " no solutions";
    //     return 0;
    // }
    // if ((a > 0) and (b == 0))
    // {
    //     cout << "==============" << endl;
    //     cout << "ANSWER " << "x = 0";
    //     return 0;
    // }
    // xq = -b / a;
    // if (xq < 0)
    // {
    //     cout << "==============" << endl;
    //     cout << "ANSWER " << "x1 = 0 and " << -b << "/" << a << "no solutions";
    //     return 0;
    // }
    // x = pow(-b / a, 0.5);
    // cout << "==============" << endl;
    // cout << "ANSWER " << "x1 = 0 " << "x2 = " << x << " x3 = " << -x;
    // return 0;
    
/*    if (((a > 0) and (b <= 0)) or ((a < 0) and (b >= 0)))
    {
        x = pow(-b / a, 0.5);
        cout << "x = " << x << endl;
    }
    else if (((b / a) < 0) or ((a > 0) and (b > 0)) or (a = 0))
    {
        cout << "no solutions" << endl;
        cout << "ANSWER x1 = 0 and 0/0 no solutions";
        return 0;
    }*/
    
    //====5====
/*    int n = 0, m = 0, j = 0;
    cin >> n;
    if (n < 0) return 0;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        if (m = m)
        {
            j += 1;
        }
    }
    cout << endl;
    if (j == n) cout << m;
    else cout << -1;*/
    
    //====6====
    // int n = 0, s = 0, m = 0;
    // cin >> n;
    // if (n < 0) return 0;
    // cin >> s;
    // for (int i = 0; i < n - 2; i++)
    // {
    //     cin >> m;
    //     cout << m << " ";
    // }
    
    //====7====
    int n;
    double x;
    cin >> n;
    cin >> x;
    int p = 0;
    double answ = 0;
    for (int i = 0; i < 2 * n; i += 2)
    {
        if (p % 2 == 0)
        {
            answ += pow(x, i) / fac(i);
        } else 
        {
            answ -= pow(x, i) / fac(i);
        }
        p ++;
    }
    cout << "ANSWER " << answ;

}
