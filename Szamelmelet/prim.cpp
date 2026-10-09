#include <iostream>

using namespace std;

bool prim(int szam)
{
    for(int oszto = 2; oszto * oszto <= szam; oszto++)
    {
        if(szam % oszto == 0)
            return false;
    }
    return true;
}

int main()
{
    for (int i = 1; i < 100; i++)
    {
        if(prim(i))
            cout << i << endl;
    }
    return 0;
}
