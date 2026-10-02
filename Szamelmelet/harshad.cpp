#include <iostream>

using namespace std;

int szamjegyekOsszege(int szam)
{
    int osszeg = 0;
    while(szam > 0)
    {
        osszeg = osszeg + szam % 10;
        szam = szam / 10;
    }
    return osszeg;
}

bool harshad(int szam)
{
    return szam % szamjegyekOsszege(szam) == 0;
}

int main()
{
    cout << "Harshad szamok:" << endl;
    for (int i = 1; i < 1000; i++)
    {
        if (harshad(i))
            cout << i << endl;
    }
    return 0;
}
