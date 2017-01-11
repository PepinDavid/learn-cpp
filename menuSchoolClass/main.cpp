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

void destructNotes(Eleve * &el, int &nb)
{
    delete [] el[nb].notes;
}

//destruction du pointeur Eleve et du pointeur [] notes appartenant a Eleve[i]
void destructEleve(Eleve * &els, int &taille)
{
    cout << "Destruction pointeur Eleve addresse memoire : " << els << endl;

    if(taille < 1)
    {
        return;
    }
    for(int i = 0; i < taille; i++)
    {
        destructNotes(els,i);
    }
    delete [] els;
}

//creation d'un Eleve
void setEleve(Eleve * &el, int num = -1)
{
    if(num == -1)
    {
        cout << "Quel numero d'eleve ? " << endl;
        cin >> num;
    }

    cout << "Eleve numero : " << num << endl;
    cout << "Entrez le nom : ";
    cin >> ws;//ws est un manipulateur de cin, il permet de ne pas
    //s'arrete aux espaces dans les chaines de caractere;
    cin.get(el[num].nom, MAXLETTRES);

    //Vidage de la memoire tampon
    //evite de recupéré des lettres si depassement de MAXLETTRE
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Entrez le prénom : ";
    cin >> ws;//ws est un manipulateur de cin, il permet de ne pas
    //s'arrete aux espaces dans les chaines de caractere;
    cin.get(el[num].prenom, MAXLETTRES);

    //Vidage de la memoire tampon
    //evite de recupéré des lettres si depassement de MAXLETTRE
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    do
    {
        cout << "Combien de notes : ";
        cin  >> el[num].nbNotes;
    }while(el[num].nbNotes < 0);

    cout << "adresse memoire notes eleve" << el[num].notes << endl;
    for(int j = 0; j < el[num].nbNotes; j++)
    {
        cout << j+1 << " notes" << endl;
        cin >> el[num].notes[j];
    }
    cout << "\n" << endl;
}

//lit la classe
void readClassRoom(Eleve * &el, int &t)
{
    int modif = -1;
    if(t < 1)
    {
        cout << "Definir la classe en premier " << el << endl;
        return;
    }
    cout << "Recap addresse memoire!!! " << el << endl;

    for(int i = 0; i < t; i++)
    {
        cout << "- " << i;
        cout << " - Nom et prénom  : " << el[i].nom << " " << el[i].prenom << endl;
        for(int j = 0; j < el[i].nbNotes; j++)
        {
            cout << "\t note "<< j+1 << " -- " << el[i].notes[j] << endl; //donne valeur
        }
        cout << "\n" << endl;
    }

    do
    {
        cout << "Modifier un eleve ? " << endl;
        cout << "0 -- non " << endl;
        cout << "1 -- oui" << endl;
        cin >> modif;
    }while(modif > 1);

    if(modif == 1)
    {
        setEleve(el);
    }
    else
    {
        return;
    }
}

//création de la classe
void setClasse(Eleve * &el, int &sizeClasse)
{
    cout << "Recap addresse memoire!!! " << el << endl;
    if(sizeClasse > 0)
    {
        destructEleve(el, sizeClasse);
    }
    do
    {
        cout << "Combien d'élèves a déclaré  ? " << endl;
        cin >> sizeClasse;
        if(sizeClasse < 0)
            cout << "Le nombre d'élève doit forcement etre superieur a 1" << endl;
    }while(sizeClasse < 0);
    el = new Eleve[sizeClasse];
    cout << "adresse memoire els apres declaration taille classe : " << el << endl;

    for(int i = 0; i < sizeClasse; i++)
    {
        setEleve(el, i);
    }
}

//donne l'adresse memoire du pointeur Eleve et les adresses memoires de Eleve[i].notes
void adressMemories(Eleve * &els, int &sizeClasse)
{
    cout << "Recap addresse memoire array Eleve * els !!! " << els << endl;
    if(sizeClasse < 0)
    {
        return;
    }

    for(int i = 0; i < sizeClasse; i++)
    {
        cout << "Recap addresse memoire array Eleve * els["<< i <<"].notes !!! " << els[i].notes << endl;
    }
}

void affichMenu()
{
    cout << "--- MENU ---" << endl;
    cout << "1 - Création de la classe" << endl;
    cout << "2 - Afficher la classe" << endl;
    cout << "3 - Graphique" << endl;
    cout << "4 - QUITTER" << endl;
    cout << "5 - Memories adress" << endl;
    cout << "Faire un choix" << endl;
}

void loadGraph()
{
    return;
}

int main()
{
    int taille = 0, choise = -1;
    Eleve * els = 0;
    bool quit = true;
    cout << "adresse memoire els : " << els << endl;

    while(quit)
    {
        affichMenu();
        cin >> choise;
        switch(choise)
        {
            case 1:
                setClasse(els, taille);
                break;
            case 2:
                readClassRoom(els, taille);;
                break;
            case 3:
                loadGraph();
                break;
            case 4:
                destructEleve(els, taille);
                quit = false;
                break;
            case 5:
                adressMemories(els, taille);
                break;
            default:
                affichMenu();
                break;
        }
    }

    return 0;
}
