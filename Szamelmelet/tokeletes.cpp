#include <iostream>

using namespace std;

int osztokOsszege(int szam)
{
    int ossz = 1;
    for(int oszto = 2; oszto * oszto <= szam; oszto++)
    {
        if (szam % oszto == 0)
        {
            ossz = ossz + oszto;
            if(oszto != szam / oszto)
                ossz = ossz + szam / oszto;
        }
    }
    return ossz;
}

bool tokeletesszam(int szam)
{
    return osztokOsszege(szam) == szam;
}

int main()
{
    cout << "Tokeletes szamok: " << endl;
    for (int i = 1; i < 1000000000; i++)
    {
        if(tokeletesszam(i))
            cout << i << endl;
    }
    return 0;
}
