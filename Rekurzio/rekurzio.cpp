#include <iostream>

using namespace std;

void valami(int n)
{
    if(n <= 0)
        return;
    cout << n << " .szia" << endl;
    valami(n - 1);
}

int gaussKeplet(int n)
{
    return n * (n + 1) / 2;
}

int gauss(int n)
{
    int ossz = 0;
    while(n > 0)
    {
        ossz = ossz + n;
        n--;
    }
    return ossz;
}

int gauss_r(int n)
{
    if(n <= 0)
        return 0;
    return n + gauss_r(n - 1);
}

int fibonacci(int n)
{
    int elso = 0, masodik = 1, aktualis = 1;
    for(int i = 2; i <= n; i++)
    {
        elso = masodik;
        masodik = aktualis;
        aktualis = elso + masodik;
    }
    return masodik;
}

int fibonacci_r(int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return fibonacci_r(n - 1) + fibonacci_r(n - 2);
}

int faktorialis(int n)
{
  int szorzat = 1;
  for(int i = 1; i <= n; i++)
  {
      szorzat = szorzat * i;
  }
  return szorzat;
}

int faktorialis_r(int n)
{
    if(n == 0)
        return 1;
    return n * faktorialis_r(n - 1);
}

int hatvany(int alap, int kitevo)
{
    int szorzat = 1;
    for(int i = 1; i <= kitevo; i++)
    {
        szorzat = szorzat * alap;
    }
    return szorzat;
}

int hatvany_r(int alap, int kitevo)
{
    if(kitevo == 0)
        return 1;
    return alap * hatvany_r(alap, kitevo - 1);
}

int gyorsHatvany(int a, int k)
{
    int eredmeny = 1;
    while(k > 0)
    {
        if(k % 2 == 0) //paros
        {
            a = a * a;
            k = k / 2;
        }
        else //paratlan
        {
            eredmeny = eredmeny * a;
            k--;
        }
    }
    return eredmeny;
}

int gyorsHatvany_r(int a, int k)
{
    if(k == 0)
        return 1;
    if(k % 2 == 0) //paros
        return gyorsHatvany_r(a * a, k / 2);
    else //paratlan
        return a * gyorsHatvany_r(a, k - 1);
}

int lnko(int a, int b)
{
    while(b != 0)
    {
        int r = a % b; //maradek
        a = b;
        b = r;
    }
    return a;
}

int lnko_r(int a, int b)
{
    if(b == 0)
        return a;
    return lnko_r(b, a % b);
}

void kiir_r(int n)
{
    if(n == 0)
        return;
    cout << n;
    kiir_r(n-1);
    kiir_r(n-1);
}
/*
s(0) -> ures
s(1) -> 1s(0)
s(2) -> 211 -> 21s(1)
s(3) -> 3211211 -> 321s(1)s(2)
s(4) -> 432112113211211 -> 4321s(1)s(2)s(3)
s(5) -> 5432112113211211432112113211211 -> 54321(1)s(2)s(3)s(4)
        5432112113211211432112113211211
*/

int main()
{
    valami(10);
    cout << "gauss keplet" << gaussKeplet(10) << endl;
    cout << "gauss" << gauss(10)<<endl;
    cout << "gauss rekurziv " << gauss_r(10) << endl;
    cout << "fibonacci " << fibonacci(10) << endl;
    cout << "fibonacci rekurziv " << fibonacci_r(10) << endl;
    cout << "gyors hatvany " << gyorsHatvany(2, 10) << endl;
    cout << "gyors hatvany rekurziv " << gyorsHatvany_r(2, 10) << endl;
    kiir_r(5);
    cout << endl;
    return 0;
}
