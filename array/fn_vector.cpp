#include <iostream>
#include <string>
#include <vector>
#include "fn_vector.h"

using namespace std;

double doMoyenne(vector<double>& arr)
{
    double total(0);
    int sisze(arr.size());
    for(int i = 0; i < sisze; i++)
    {
        total += arr[i];
    }
    total /= sisze;
    return total;
}

void writeVectorNb( vector<double>& arr, int& nbr, string s = "case")
{
    double nb(0);
    for(int i = 0; i < nbr; i++)
    {
        cout << "Remplissage de la" << s << " : " << i << endl;
        cin >> nb;
        arr.push_back(nb);
    }
}
