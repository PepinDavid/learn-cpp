#include <iostream>
#include <limits>
using namespace std;

const int MAXLETTRES = 16;

//utilisable en C, struct est une variable évolué
struct Eleve
{
    char nom[MAXLETTRES], prenom[MAXLETTRES];
    int nbNotes;
    float * notes = new float[nbNotes];
};

int main()
{

    //pointeur !
    //declaration d'un pointeur;
    int * ptr = 0; // !!!!!!!!!!!!! TOUJOURS INITIALISé a 0 sinon on recupere
    //le pointeur memoire d'un processus deja en route !!!!

    //declaration d'un pointeur avec allocation memoire dynamique
    int * point = new int; // ici le pointeur recoit une adresse memoire
    //a nous de le definir par la suite

    cout << "valeur pointeur ptr " << ptr << endl;
    cout << "valeur pointeur point " << point << endl;

    cout << "test egalité entre pointeur avant delete" << endl;

    int * p = point;
    cout << "valeur pointeur p " << p << endl;

    delete point;

    cout << "test egalité entre pointeur apres delete" << endl;

    //int * p = point;

    cout << "valeur pointeur p " << p << endl;

    //delete p;
    //quand delete point est fait sa delete p egalement car c'est la meme adresse memoire

    int taille, tall;
    do
    {
        cout << "Combien d'élèves a déclaré  ? " << endl;
        cin >> taille;
        if(taille < 0)
            cout << "Le nombre d'élève doit forcement etre superieur a 1" << endl;
    }while(taille < 0);

    //Dans ce cas le pointeur permet de créer un tableau dynamique
    Eleve * els = new Eleve[taille];

    cout << "Hello world!" << endl;
    cout << "adresse pointeur du tableau Eleve : " << els << endl;
    for(int i = 0; i < taille; i++)
    {
        cout << "Eleve numero : " << i+1 << endl;
        cout << "Entrez le nom : ";
        cin >> ws;//ws est un manipulateur de cin, il permet de ne pas
        //s'arrete au espace dans les chaines de caractere;
        cin.get(els[i].nom, MAXLETTRES);

        //Vidage de la memoire tampon
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Entrez le prénom : ";
        cin >> ws;//ws est un manipulateur de cin, il permet de ne pas
        //s'arrete au espace dans les chaines de caractere;
        cin.get(els[i].prenom, MAXLETTRES);

        //Vidage de la memoire tampon
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        do
        {
            cout << "Combien de notes : ";
            cin  >> els[i].nbNotes;
        }while(els[i].nbNotes < 0);

        for(int j = 0; j < els[i].nbNotes; j++)
        {
            cout << j+1 << " notes" << endl;
            cin >> els[i].notes[j];
        }
        cout << "\n" << endl;
    }

    cout << "Recap !!! " << endl;

    for(int i = 0; i < taille; i++)
    {
        cout << "Eleve numero : " << i+1 << endl;
        cout << "adresse memoire du pointer els : " << els << endl;
        cout << "adresse memoire de la variable &els["<< i << "]/struct Eleve["<< i << "] : " << &els[i] << endl; //donne adresse memoire grace a la reference &
        cout << "Nom et prénom  : " << els[i].nom << " " << els[i].prenom << endl;
        for(int j = 0; j < els[i].nbNotes; j++)
        {
            cout << "adresse pointer els["<< i << "].notes : " << els[i].notes << endl;
            cout << "adresse de &els["<< i << "].notes["<< j << "] : " << &els[i].notes[j] << endl; //donne adresse memoire grace a la reference &
            cout << "adresse de els["<< i << "].notes["<< j << "] : " << els[i].notes[j] << endl; //donne valeur
        }
        cout << "\n" << endl;
        delete [] els[i].notes;
    }
    delete [] els;

    cout << "Test réatribution de valeur apres delete des pointeurs" << endl;

    cout << "adresse memoire du pointer els : " << els << endl;
    cout << "adresse memoire de la variable &els[0]/struct Eleve[0] : " << &els[0] << endl; //donne adresse memoire grace a la reference &
    cout << "attribution nouveau nom et prenom " << endl;
    cout << "Entrez le nouveau nom : ";
    cin >> ws;//ws est un manipulateur de cin, il permet de ne pas
    //s'arrete au espace dans les chaines de caractere;
    cin.get(els[0].nom, MAXLETTRES);

    //Vidage de la memoire tampon
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Nom et prénom  : " << els[0].nom << " " << els[0].prenom << endl;
    cout << "\n" << endl;

    return 0;
}
