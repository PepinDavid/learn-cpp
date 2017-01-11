#include <iostream>
#include "fn_array.h"

using namespace std;

void writeArray(int arr[], int sizeTab)
{
    double nb(0);
    for(int i = 0; i < sizeTab; i++)
    {
        cout << "Remplissage de la case : " << i << endl;
        cin >> nb;
        arr[i] = nb;
    }
}

void seeArray(int tab[], int sizeTab)
{
    for(int i = 0; i <  sizeTab; i++)
    {
        cout << "Le score : " << i << " est : " << tab[i] << endl;
    }
}
