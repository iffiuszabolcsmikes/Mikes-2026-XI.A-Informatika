#include <iostream>

using namespace std;

int valami()
{
    return 69;
}

void szamjegyek()
{
    for(int i = 0 ; i < 10; i++)
        cout << i << " ";
    cout << endl;
}

int osszead(int x, int y)
{
    return x + y;
}

float hatvany(int alap, int kitevo)
{
    float eredmeny = 1;
    while(kitevo > 0)
    {
        eredmeny = eredmeny * alap;
        kitevo--;
    }
    return eredmeny;
}

int main()
{
    cout << "Fuggvenyek!" << endl;
    cout << valami() << endl;
    szamjegyek();
    cout << osszead(5, 8) << endl;
    cout << hatvany(2, 3) << endl;

    return 0;
}
