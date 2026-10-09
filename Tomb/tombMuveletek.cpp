#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

const int N = 100; //tomb kapacitas

void feltoltVeletlen(int tomb[], int n)
{
    for(int i = 0; i < n; i++)
    {
        tomb[i] = rand() % 100;
    }
}

void kiir(int tomb[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << setw(3) << i <<".";

    }
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        cout << setw(3) << tomb[i] << " ";

    }
    cout << endl;
}

int osszeg(int tomb[], int n)
{
    int ossz = 0;
    for(int i = 0; i < n; i++)
    {
        ossz = ossz + tomb[i];
    }
    return ossz;
}

int legkissebb(int tomb[], int n)
{
    int min = tomb[0];
    for(int i = 1; i < n; i++)
    {
        if(tomb[i] < min)
            min = tomb[i];
    }
    return min;
}

int minIndex(int tomb[], int n)
{
    int mini = 0;
    for(int i = 1; i < n; i++)
    {
        if(tomb[i] < tomb[mini])
            mini = i;
    }
    return mini;
}

int legnagyobb(int tomb[],int n)
{
    int max = tomb[0];
    for(int i = 1; i < n; i++)
    {
        if(tomb[i] > max)
            max = tomb[i];
    }
    return max;
}

int maxIndex(int tomb[],int n)
{
    int maxi = 0;
    for(int i = 1; i < n; i++)
    {
        if(tomb[i] > tomb[maxi])
            maxi = i;
    }
    return maxi;
}

bool eleme(int tomb[], int n, int keresettElem)
{
    for(int i = 0; i < n; i++)
    {
        if(tomb[i] == keresettElem)
        {
            return true;
        }
    }
    return false;
}

int elemIndexe(int tomb[], int n, int keresettElem)
{
    for(int i = 0; i < n; i++)
    {
        if(tomb[i] == keresettElem)
        {
            return i;
        }
    }
    return -1;
}

void torolElem(int tomb[], int &n, int index)
{
    for(int i = index; i + 1 < n; i++)
    {
        tomb[i] = tomb[i + 1];
    }
    n--;
}

void beszurElem(int tomb[], int &n, int index, int szam)
{
    n++;
    for(int i = n - 1; i > index; i--)
    {
        tomb[i] = tomb[i - 1];
    }
    tomb[index] = szam;
}

float atlag(int tomb[], int n)
{
    return (float)osszeg(tomb, n) / n;
}

void kiirParos(int tomb[], int n)
{
    cout << "Paros elemek:" << endl;
    for(int i = 0; i < n; i++)
    {
        if(tomb[i] % 2 == 0)
            cout << tomb[i] << " ";
    }
    cout << endl;
}

int paratlanokSzama(int tomb[], int n)
{
    int db = 0;
    for(int i = 1; i < n; i++)
    {
        if(tomb[i] % 2 != 0)
        {
            db = db + 1;
        }
    }
    return db;
}

bool prim(int szam)
{
    for(int oszto = 2; oszto * oszto <=szam; oszto++)
    {
        if(szam % oszto == 0)
            return false;
    }
    return true;
}

int primekSzama(int tomb[], int n)
{
    int db = 0;
    for(int i = 1; i < n; i++)
    {
        if(prim(tomb[i]))
        {
            db = db + 1;
        }
    }
    return db;
}

bool teljesNegyzet(int szam)
{
    int gyok = sqrt(szam);
    return gyok*gyok == szam;
}

int teljesNegyzetOssz(int tomb[], int n)
{
    int ossz = 0;
    for(int i = 0; i < n; i++)
    {
        if(teljesNegyzet(tomb[i]))
            ossz = ossz + tomb[i];
    }
    return ossz;
}

int main()
{
    srand(time(0));
    int tomb[N];
    int n = 20; //tomb merete
    feltoltVeletlen(tomb, n);
    kiir(tomb, n);
    cout << "Osszeg: " << osszeg(tomb, n) << endl;
    cout << "Legkisebb elem: " << legkissebb(tomb, n) << endl;
    cout << "Legnagyobb elem: " << legnagyobb(tomb, n) << endl;
    cout <<"67 eleme a tombnek? " << eleme(tomb, n, 67) << endl;
    cout <<"67 elso elofordulasanak indexe? " << elemIndexe(tomb, n, 67) << endl;
    cout << "2. indexen levo elem torlese" << endl;
    torolElem(tomb, n, 2);
    kiir(tomb, n);
    cout << "67 beszurasa a 2. indexre" << endl;
    beszurElem(tomb, n, 2, 67);
    kiir(tomb, n);
    cout <<"tomb atlaga: " << atlag(tomb, n) << endl;
    kiirParos(tomb, n);
    cout <<"paratlanok szama: " << paratlanokSzama(tomb, n) << endl;
    cout <<"primek szama: " << primekSzama(tomb, n) << endl;
    cout <<"teljes negyzetek osszege: " << teljesNegyzetOssz(tomb, n) << endl;
    cout <<"legkisebb elem indexe: " << minIndex(tomb, n) << endl;
    cout <<"legnagyobb elem indexe: " << maxIndex(tomb, n) << endl;
    return 0;
}
