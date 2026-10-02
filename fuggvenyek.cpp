#include <iostream>

using namespace std;

int valami()
{
    return 67;
}

void szamjegyek()
{
    cout << "szamjegyek:" << endl;
    for(int i = 0 ; i < 10; i++)
        cout << i << " ";
    cout << endl;
}

int osszeg(int a, int b)
{
    return a + b;
}

int kulonbseg(int a, int b)
{
    return a - b;
}

int szorzat(int a, int b)
{
    return a * b;
}

int hanyados(int a, int b)
{
    return a / b;
}

int maradek(int a, int b)
{
    return a % b;
}

//visszateriti a kisebbik szamot
int kisebb(int a, int b)
{
    if(a < b) return a;
    else return b;
}

int hatvany(int alap, int kitevo)
{
    float eredmeny = 1;
    while(kitevo > 0)
    {
        eredmeny = eredmeny * alap;
        kitevo--;
    }
    return eredmeny;
}

bool paros(int szam)
{
    return szam % 2 == 0;
}

int main()
{
    int a = 2, b =10;
    cout << a << " " << b << endl;
    cout << "osszeg " << osszeg(a, b) << endl;
    cout << "kulonbseg " << kulonbseg(a, b) << endl;
    cout << "szorzat " << szorzat(a, b) << endl;
    cout << "hanyados " << hanyados(a, b) << endl;
    cout << "maradek " << maradek(a, b) << endl;
    cout << "kisebb " << kisebb(a, b) << endl;
    cout << a << "^" << b << "=" << hatvany(a, b) << endl;

    if(paros(4))
    {
        cout << "paros" << endl;
    }
    else
    {
        cout << "paratlan" << endl;
    }
    szamjegyek();
    return 0;
}

