#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

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
    return 0;
}
