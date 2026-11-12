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
        cout << setw(3) << i <<"." << "|";

    }
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        cout << setw(3) << tomb[i] << " |";

    }
    cout << endl;
}

void csere(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void sortBubble(int tomb[], int n)
{
    for(int j = 0; j < n - 1; j++)
        for(int i = 0; i < n - j - 1; i++)
            if(tomb[i] > tomb[i + 1])
                csere(tomb[i], tomb[i + 1]);
}

int binarisKereses(int tomb[], int keresettElem, int also, int felso)
{
    if(also > felso)
        return -1;
    int kozepso = (also + felso) / 2;
    if(tomb[kozepso] == keresettElem)
        return kozepso;
    if(tomb[kozepso] < keresettElem)
        return binarisKereses(tomb, keresettElem, kozepso + 1, felso);
    else
        return binarisKereses(tomb, keresettElem, also, kozepso - 1);
}

int binarisKeresesIter(int tomb[], int n, int keresettElem)
{
    int also = 0;
    int felso = n - 1;
    while(also <= felso)
    {
        int kozepso = (also + felso) / 2;
        if(tomb[kozepso] == keresettElem)
            return kozepso;
        if(tomb[kozepso] < keresettElem)
            also = kozepso + 1;
        else
            felso = kozepso - 1;
    }
    return -1;
}

int main()
{
    srand(time(0));
    int tomb[N];
    int n = 20; //tomb merete
    feltoltVeletlen(tomb, n);
    tomb[0] = 67;
    kiir(tomb, n);
    sortBubble(tomb, n);
    kiir(tomb, n);
    cout << "bin ker rek  67 indexe: " << binarisKereses(tomb, 67, 0, n - 1) << endl;
    cout << "bin ker iter 67 indexe: " << binarisKeresesIter(tomb, n, 67) << endl;
    return 0;
}
