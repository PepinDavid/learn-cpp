#include <iostream>
#include <string>
#include <cmath>
#include "testMath.h"

using namespace std;

int main()
{
//    string  testString  = "Hello world! \"ça\" Gaz Gégé", autreSring = "j\'ai : ";
//    int     age         = 41;
//    double a(42), b(42);
//    string& refTestString = testString; //accées a testString par référence évite l'utilisation
//    //de mémoire en plus
//    string nameSurname(""), city("");
//
//    cout << testString << endl;
//    cout << autreSring << age << "ans" << endl;
//    cout << "test accés variable par référence : " << refTestString << endl;
//    cout << "Quel est votre nom et votre prénom ? " << endl;
//    getline(cin,nameSurname); //fonction qui sert a l'acquisition d'une phrase
//    cout << "Vous vous appelez : " << nameSurname << "\n";
//    cout << "Quel age avez vous ?" << endl;
//    cin >> age;
//    //quand on fait l'acquisition d'une variable number si on veut faire l'acquisition
//    //d'une variables de type STRING a l'aide de la fonction getline, il faut un cin.ignore()
//    cin.ignore();
//    cout << "Vous avez " << age << " ans " << endl;
//    cout << "Où habitez vous ? " << endl;
//    getline(cin, city);
//    cout << "Vous donc a : " << city << endl;
//    cout << "Addition !!! " << endl;
//    cout << "Ecrire le premier nombre à mettre dans l'addition" << endl;
//    cin >> a;
//    cout << "Ecrire le deuxieme nombre : " << endl;
//    cin >> b;
//    cout << " Addition de " << a << " + " << b << " = " << a+b << endl;
//    cout << "Comment vous appelez vous au fait ?" << endl;
//    cin.ignore();
//    getline(cin,testString);
//    cout << "Bonjour " << testString << endl;
//    cout << "Ecrire un nombre auquel on ajoutera deux : ";
//    cin >> a;
//    b = addTwo(a);
//    cout << " le nombre original : " << a << ". Qui fait donc : " << b;

	int * ptr;
	ptr = new int[3];
	for(int i = 0; i < 3; i++){
		ptr[i] = i+3;
	}
	ptr = new int [4];
	ptr[3] = 42;
	
	for(int i = 0; i < 4; i++){
		cout << ptr[i] << endl;
	} 
    return 0;
}
