#include <iostream>

using namespace std;

int szamjegyekSzama( int szam)
{
    if(szam == 0)
        return 1;

    int db=0;
    while(szam != 0)
    {
        szam = szam / 10;
        db++;
    }
    return db;
}

int szamjegyekOsszege( int szam)
{
    int osszeg = 0;
    while(szam!= 0)
    {
        osszeg = osszeg + szam % 10;
        szam = szam / 10;
    }
    return osszeg;
}

int legkisebbSzamjegy(int szam)
{
    int min = szam % 10;
    while(szam != 0){
        if(szam % 10 < min)
        {
            min = szam % 10;
        }
        szam = szam / 10;
    }
    return min;
}

int legnagyobbSzamjegy(int szam)
{
    int max=szam%10;
    while(szam != 0)
    {
        if(szam % 10 > max)
        {
            max = szam % 10;
        }
        szam = szam / 10;
    }
    return max;
}

int elsoSzamjegy(int szam)
{
    while(szam <-9 || szam >9)
    {
        szam=szam/10;
    }
    return szam;
}

int main()
{
    int szam;
    cout << "szam: ";
    cin >> szam;
    cout << "szamjegyek szama: " << szamjegyekSzama(szam) << endl;
    cout << "szamjegyek osszege: " << szamjegyekOsszege(szam) << endl;
    cout << "legkisebb szamjegy: " << legkisebbSzamjegy(szam) << endl;
    cout << "legnagyobb szamjegy: " << legnagyobbSzamjegy(szam) << endl;
    cout << "elso szamjegy: " << elsoSzamjegy(szam) << endl;
    return 0;
}
