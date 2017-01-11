/*
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "GL/glut.h"

#include "Player.h"
using namespace std;

int nbColumns(0), nbLines(0);
int endX(0), endY(0);
char ** matrice; // pointeur de pointeurs == tableau dynamique de tableaux dynamiques
int main(int argc, char **argv)
{
    Player * a = NULL;
    cout << a << endl;
    a = new Player(5, 10);
    Player b = * a; //copie de l'objet
	printf("hello world\n");
    cout << "memory adress ptr" << endl;
    cout << a << endl;
    cout << "memory adress reference object" << endl;
    cout << &b << endl;
    cout << "position via ptr" << endl;
    cout << a->getPosX() << endl;
    cout << "position via copie objet" << endl;    
    cout << b.getPosY() << endl;
    delete a;
    cout << "Apres delete" << endl;
    cout << a << endl;
    cout << a->getPosX() << endl;
    cout << b.getPosY() << endl;
    int x(0), y(0);
    cin >> x;
    cin >> y;
    a->setPosX(x);
    b.setPosY(y);
    cout << a->getPosX() << endl;
    cout << b.getPosY() << endl;
    a = NULL;
    cout << "a = NULL" << endl;
    cout << a << endl;
    //cout << a->getPosX() << endl; // ptr = NULL fait planter !!!
    cout << b.getPosY() << endl;
	return 0;
}
*/