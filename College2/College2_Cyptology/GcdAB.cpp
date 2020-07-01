#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    int rm, rm2, q;
    rm = a;
    rm2 = b;
    while (rm2 != 0)
    {
        int trm = rm2;
        q = rm / rm2;
        rm2 = rm - q * rm2;
        rm = trm;
    }
    // cout << rm << endl;
    return rm;
}
int extendedGcd(int a, int b, int *sa, int *tb)
{
    int a0 = a, b0 = b, t0 = 0, t = 1, s0 = 1, s = 0;
    int q = a0 / b0;
    int r = a0 - q * b0;
    while (r > 0)
    {
        int temp = t0 - q * t;
        t0 = t;
        t = temp;
        temp = s0 - q * s;
        s0 = s;
        s = temp;
        a0 = b0;
        b0 = r;
        q = a0 / b0;
        r = a0 - q * b0;
    }
    r = b0;
    *sa = s;
    *tb = t;
    return r;
}
int main(int argc, char const *argv[])
{
    int A, B;
    cout << "input a:" << endl;
    cin >> A;
    cout << "input b:" << endl;
    cin >> B;
    int s, t;
    if (A > B)
    {
        cout << gcd(A, B) << endl;
        cout << extendedGcd(A, B, &s, &t) << endl;
        cout << "s=" << s << " t=" << t << " sa+tb=" << s * A + t * B << endl;
    }
    else
    {
        cout << gcd(B, A) << endl;
        int c = B;
        B = A;
        A = c;
        cout
            << extendedGcd(A, B, &s, &t) << endl;
        cout << "s=" << s << " t=" << t << "sa+tb=" << s * A + t * B << endl;
    }
    return 0;
}
