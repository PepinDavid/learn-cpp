#include <iostream>
#include <limits>
#include "GL/glut.h"

using namespace std;

const int MAXLETTRES = 16;
//utilisable en C, struct est une variable évolué
struct Eleve
{
    char nom[MAXLETTRES], prenom[MAXLETTRES];
    int nbNotes;
    double moyenne;
    float * notes = 0; //declaration pointeur
};

//pointeur mis en global pour utilsation dans glut
Eleve * els = 0;
int taille = 0;

void destructNotes(Eleve &el)
{
    delete [] el.notes;
}

//destruction du pointeur Eleve et du pointeur [] notes appartenant a Eleve[i]
void destructEleve(Eleve * &els, int &taille)
{
    cout << "Destruction pointeur Eleve addresse memoire : " << els << endl;

    if(taille < 1)
    {
        return;
    }
    if(els != 0) 
    {
        for(int i = 0; i < taille; i++)
        {
            destructNotes(els[i]);
        }
        delete [] els;
    }
}

//faire la moyenne d'un eleve
void doAverage(Eleve &el)
{
	double avg(0.00);
	for(int i = 0; i < el.nbNotes; i++)
	{
		avg += el.notes[i];
	}
	
	el.moyenne = avg/el.nbNotes;
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
        if(el[num].nbNotes > 0)
            el[num].notes = new float[el[num].nbNotes];
    }while(el[num].nbNotes < 0);

    //cout << "adresse memoire notes eleve" << el[num].notes << endl;
    for(int j = 0; j < el[num].nbNotes; j++)
    {
		do
		{
			cout << j+1 << " notes" << endl;
			cin >> el[num].notes[j];			
		}while(el[num].notes[j] > 20);
    }
	doAverage(el[num]);
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
    //cout << "Recap addresse memoire!!! " << el << endl;

    for(int i = 0; i < t; i++)
    {
        cout << "- " << i;
        cout << " - Nom et prénom  : " << el[i].nom << " " << el[i].prenom << endl;
        for(int j = 0; j < el[i].nbNotes; j++)
        {
            cout << "\t note "<< j+1 << " -- " << el[i].notes[j] << endl; //donne valeur
        }
		cout << "Moyenne de l'élève : " << el[i].moyenne << endl;
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
    //cout << "Recap addresse memoire!!! " << el << endl;
    if(sizeClasse > 0) //si classe deja existant on detruit le pointeur
    //pour creer une nouvelle "classe"
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
    //cout << "adresse memoire els apres declaration taille classe : " << el << endl;

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

void GraphiqueAffichage()
{
    //definit couleur de fond
    glClearColor(1.0, 1.0, 1.0, 1.0);
    
    //efface l'ecran
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    
	glColor3d(0.0, 0.0, 1.0); //mise en noir de la ligne que l'on va tracé
    //instructions d'affichages
	//commence l'affichage d'une ligne brisée
	glBegin(GL_LINE_STRIP); 
	//place les points
	for(int i = 0; i < taille; i++)
	{
		glVertex2d(i, els[i].moyenne);
	}
	//termine la ligne
	glEnd();
    
    //repere
    glColor3d(0.3, 0.3, 1.0);
	glBegin(GL_LINES);
    for(int i = 0; i <=20; i+=5)
    {
        glVertex2d(0, i);
        glVertex2d(taille-1, i);
    }
    glEnd();
    
    //fin affichage
    glFlush();
}

void GraphiqueResize(int x, int y)
{
    glViewport(10, 10, x-20, y-20);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, taille-1, 0.0, 20.1);
}

void Graphique(int &argc, char **argv) //on passe en parametre les arguments de la fonction main !!!
{
    //initialisation de glut
    glutInit(&argc, argv);
    //creation de la fenetre
    glutInitWindowPosition(10, 10);
    glutInitWindowSize(640, 480);
    
    //type d'affichage
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    
    //affichage de la fenetre
    glutCreateWindow("Graphique");
    
    //specifie les fonctions d'affichage
    glutDisplayFunc(GraphiqueAffichage);
    //et de redimentionnement
    glutReshapeFunc(GraphiqueResize);
    
    //lance la boucle d'affichage
    glutMainLoop();
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

int main(int argc, char **argv)
{
    int choise = -1;
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
                Graphique(argc, argv);
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
