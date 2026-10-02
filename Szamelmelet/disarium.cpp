#include <iostream>

using namespace std;

int szamjegyekSzama(int szam)
{
    if (szam==0)
        return 1;

    int db = 0;
    while(szam != 0)
    {
        szam = szam / 10;
        db++;
    }
    return db;
}

int hatvany(int alap, int kitevo)
{
    int eredmeny = 1;
    while(kitevo > 0)
    {
        eredmeny = eredmeny * alap;
        kitevo--;
    }
    return eredmeny;
}

bool disarium(int szam)
{
    int szsz = szamjegyekSzama(szam);
    int osszeg = 0;
    int eredeti = szam;
    while(szam != 0)
    {
        osszeg = osszeg + hatvany(szam % 10, szsz);
        szam = szam / 10;
        szsz--;
    }
    return eredeti == osszeg;
}

int main()
{
    cout << "Disarium szamok: " << endl;
    for (int i = 0; i < 1000000000; i++)
    {
        if (disarium(i))
            cout << i << endl;
    }
    return 0;
}
