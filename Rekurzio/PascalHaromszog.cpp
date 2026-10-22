#include <iostream>

using namespace std;

//C(n,k) = n*C(n-1,k-1)/k
int kombinacio_r(int n, int k)
{
    if(k == 0)
        return 1;
    return n * kombinacio_r(n - 1, k - 1) / k;
}

void pascal3szog(int n)
{
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cout << kombinacio_r(i, j) << " ";
        }
        cout << endl;
    }
}

void newtonBinom(int n)
{
    cout << "(a+b)^0 = 1" << endl;

    for(int i = 1; i <= n; i++)
    {
        cout << "(a+b)^" << i << " = ";
        for(int j = 0; j <= i; j++)
        {

            int e = kombinacio_r(i, j);
            if(e != 1)
                cout << e;
            if(i - j == 1)
                cout << "a";
            if(i - j > 1)
                cout << "a^" << i - j;
            if(j == 1)
                cout << "b";
            if(j > 1)
                cout << "b^" << j;
            if(j < i)
                cout << "+";
        }
        cout << endl;
    }
}

int main()
{
    cout << "Pascal haromszog" << endl;
    pascal3szog(5);
    cout << "Newton binomialis keplete" << endl;
    newtonBinom(5);
    return 0;
}
