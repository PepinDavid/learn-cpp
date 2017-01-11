#include <iostream>
#include <string>
#include <vector>
#include "fn_vector.h"
#include "fn_array.h"

using namespace std;

int main()
{

    int const sizeTab(5);
    int score[sizeTab]; // tableau avec des tailles fixe !!!
    int sizeArray((sizeof(score)/sizeof(*score)));
    cout << "Taille du tableau de score : " << (sizeof(score)/sizeof(*score)) << endl;
    cout << "Sizeof du tableau : " << sizeof(score) << endl;
    cout << "Sizeof de  * tableau : " << sizeof(*score) << endl; //equivalent .length du tableau
    writeArray(score, sizeTab);
    seeArray(score, sizeTab);

    int nbNotes;
    vector<double> notes;

    cout << "faire la moyenne, combien de notes avez vous a remplir ? " << endl;
    cin >> nbNotes;
    cout << "vous avez " << nbNotes << " notes a remplir" << endl;
    writeVectorNb(notes, nbNotes, "note numéro");
    cout << "calcule de la moyenne !!! " << endl;
    cout << doMoyenne(notes) << endl;

    cout << "fin du programme ";


    return 0;
}
