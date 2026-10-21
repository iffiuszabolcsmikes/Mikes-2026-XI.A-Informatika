#include <iostream>

using namespace std;

//1*2*3*...*n
int permutacio(int n)
{
    /*for(int i = 1; i <= n; i++)
    {
        szorzat = szorzat * i;
        szorzat *= i;
    }*/

    int szorzat = 1;
    while(n > 0)
    {
        szorzat *= n;
        n--;
    }
    return szorzat;
}
//(n-k+1)*(n-k+2)*...*n
int variacio(int n, int k)
{
    int szorzat = 1;
    for(int i = n - k + 1; i <= n; i++)
    {
        szorzat *= i;
    }
    return szorzat;
}
//C(n,k) = V(n, k)/P(k)
int kombinacio(int n, int k)
{
    int v = 1;
    int p = 1;
    for(int i = n - k + 1; i <= n; i++)
    {
        v *= i;
    }
    for(int i = 1; i <= k; i++)
    {
        p *= i;
    }
    return v / p;
}
//P(n) = n*P(n-1)
int permutacio_r(int n)
{
    if(n == 0)
        return 1;
    return n * permutacio_r(n - 1);
}
//V(n,k) = n*V(n-1,k-1)
int variacio_r(int n, int k)
{
    if(k == 0)
        return 1;
    return n * variacio_r(n - 1, k - 1);
}
//C(n,k) = n*C(n-1,k-1)/k
int kombinacio_r(int n, int k)
{
    if(k == 0)
        return 1;
    return n * kombinacio_r(n - 1, k - 1) / k;
}

int main()
{
    cout << "P   " << permutacio(5) << endl;
    cout << "P_r " << permutacio_r(5) << endl;
    cout << "V   " << variacio(10, 7) << endl;
    cout << "V_r " << variacio_r(10, 7) << endl;
    cout << "C   " << kombinacio(10, 7) << endl;
    cout << "C_r " << kombinacio_r(10, 7) << endl;
    return 0;
}
