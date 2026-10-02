#include <iostream>

using namespace std;

int megfordit(int szam)
{
    int forditott = 0;
    while(szam != 0)
    {
        forditott = forditott * 10 + szam % 10;
        szam = szam / 10;
    }
    return forditott;
}

bool tukorszam (int szam)
{
    return szam == megfordit(szam);
    /*if(szam == megfordit(szam))
        return true;
    else
        return false;*/
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

int main()
{
    cout << "Tukorprim szamok: " << endl;
    for(int i=0; i < 1000; i++)
    {
        if (tukorszam(i) && prim(i))
            cout << i << endl;
    }

    return 0;
}
