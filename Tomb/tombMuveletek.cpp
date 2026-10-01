#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//tomb kapacitas
const int N = 100;

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
        cout << tomb[i] << " ";
    }
    cout << endl;
}

int osszeg(int tomb[], int n)
{
    int ossz = 0;
    for(int i  =0; i < n; i++)
    {
        ossz = ossz + tomb[i];
    }
    return ossz;
}

int legkissebb(int tomb[], int n)
{
    int min = tomb[0];
    for(int i = 0; i < n; i++)
    {
        if(tomb[i] < min)
            min = tomb[i];
    }
    return min;
}

int legnagyobb (int tomb[],int n)
{
    int max = tomb[0];
    for(int i = 0; i < n; i++)
    {
        if(tomb[i] > max)
            max = tomb[i];
    }
    return max;
}

int main()
{
    srand(time(0));
    int tomb[N];
    //tomb merete
    int n = 20;
    feltoltVeletlen(tomb, n);
    kiir(tomb, n);
    cout << "Osszeg: " << osszeg(tomb, n) << endl;
    cout << "Legkissebb elem: " << legkissebb(tomb, n) << endl;
    cout << "Legnagyobb elem: " << legnagyobb(tomb, n) << endl;
    return 0;
}
