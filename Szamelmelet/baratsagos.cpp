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

int main()
{
    cout << "Baratsagos szamok: " << endl;
    for (int i = 1; i < 1000000000; i++)
    {
        int ossz = osztokOsszege(i);
        if(osztokOsszege(ossz) == i)
            cout << i << " " << ossz << endl;
    }
    return 0;
}
