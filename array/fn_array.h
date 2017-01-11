#ifndef FN_ARRAY_H_INCLUDED
#define FN_ARRAY_H_INCLUDED

//les fonctions ne peuvent pas renvoyé de tableau,
// si un tableau est en argument il sera forcement par reference et donc modifiable dans la fonction !!!
void writeArray(int arr[], int sizeTab);

void seeArray(int tab[], int sizeTab);

#endif // FN_ARRAY_H_INCLUDED
