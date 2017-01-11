#ifndef FN_VECTOR_H_INCLUDED
#define FN_VECTOR_H_INCLUDED

#include <vector>

using namespace std;
//fonction qui prend en argument la reference d'un tableau dynamique
//                               la reference constante d'un nombre entier
//                               une string qui par defaut a une valeur
//grace au referencement de notre tableau dynamique nous n'avons pas besoin
//de retourné un nouveau tableau !!! se qui aurait de la memoire en plus pour rien !!!
void writeVectorNb( vector<double>& arr, int& nbr, string s);

// attention !!! vector.size fonctionne car quand, la fn est utilisé sa taille est deja defini
// l'args nb est facultatif car declaré directement dans la fonction
double doMoyenne(vector<double>& arr);


#endif // FN_VECTOR_H_INCLUDED
