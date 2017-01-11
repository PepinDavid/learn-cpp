#include <stdio.h>
#include <iostream>
#include <fstream>

#include "GL/glut.h"

#include "Player.h"
#include "MonsterGreen.h"

using namespace std; 

int nbColumns(0), nbLines(0);
int endX(0), endY(0);
char ** matrice; // pointeur de pointeurs == tableau dynamique de tableaux dynamiques
Player firstPlayer(0,0, false);
MonsterGreen mGreen;

void labyAffichage();
void labyRedim(int x, int y);
void labySpecialKeyboard(int key, int x, int y);
void openFile(char * name_file); //char * = tableau de char = char [] == pointeur
void drawLevel();
void freeMemories();
void gameOver();

int main(int argc, char **argv)
{	
    matrice = NULL;

    //init glut
    glutInit(& argc, argv);
    glutInitWindowPosition(10, 10);
    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_RGBA |GLUT_SINGLE);
    glutCreateWindow("Labyrinthe");
    glutDisplayFunc(labyAffichage);
    mGreen.goDown();
    glutPostRedisplay();
    glutReshapeFunc(labyRedim);
    glutSpecialFunc(labySpecialKeyboard);
    openFile("/home/david/dev/c++/jeuLabyrinthe/labyWithClassParent/levelone");
    cout << "position MR Green : "; 
    cout << mGreen.getPosX() << endl;
    cout << mGreen.getPosY() << endl;
    cout << "position firstPlayer : "; 
    cout << firstPlayer.getPosX() << endl;
    cout << firstPlayer.getPosY() << endl;
    firstPlayer.getName();
    
    glutMainLoop();
    
	return 0;
}


void labyAffichage()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    
    //instruction d'affichage
    drawLevel();
    mGreen.draw();
    firstPlayer.draw();
    glutSwapBuffers();
}

void labyRedim(int x, int y)
{
    
    glViewport(0, 0, x, y);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (double)nbColumns, (double)nbLines, 0.0);
}

void labySpecialKeyboard(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_UP:
            firstPlayer.goUp();
            break;
        case GLUT_KEY_DOWN:
            firstPlayer.goDown();
            break;
        case GLUT_KEY_LEFT:
            firstPlayer.goLeft();
            break;
        case GLUT_KEY_RIGHT:
            firstPlayer.goRight();
            break;
    }
    gameOver();
    glutPostRedisplay();
}
void openFile(char * nom_file)
{
    ifstream file;
    file.open(nom_file);
    
    if(file.good() == false)
    {
        cout << "Une erreur est survenu lors de l'ouverture du fichier : " << nom_file << endl;
        exit(1);
    }
    file >> nbColumns;
    file >> nbLines;
    
    //initialisation longueur de la matrice
    matrice = new char * [nbColumns];
    for(int i = 0; i < nbColumns; i++)
        matrice[i] = new char [nbLines];
        
    //initialisation de chaque elements des tableaux a "0"
    for(int i = 0; i < nbColumns; i++)
        for(int j = 0; j < nbLines; j++)
            matrice[i][j] = '0';
            
    for(int j = 0; j < nbLines; j++)
        for(int i = 0; i < nbColumns; i++)
        {
            file >> matrice[i][j];
            switch(matrice[i][j])
            {
                case 'j':
                case 'J':
                    firstPlayer.setPosX(i);
                    firstPlayer.setPosY(j);
                    break;
                case 's':
                case 'S':
                    endX = i;
                    endY = j;
                    break;
            }
        }
    
    file.close();
}

void drawLevel()
{
    glColor3d(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);//commence l'affichage du quatrillage
    
    for(int i = 0; i < nbColumns; i++)
            for(int j = 0; j < nbLines; j++)
                if(matrice[i][j] == '0')
                {
                    glVertex2d(i, j);
                    glVertex2d(i, j+1);
                    glVertex2d(i+1, j+1);
                    glVertex2d(i+1, j);
                }
                
    glEnd();
    
    //affichage point de sorti
    glPushMatrix();
    glTranslated(endX + 0.5, endY + 0.5, 0.0);
    glColor3d(0.3, 1.0, 0.3);
    for(double taille = 0.1; taille < 1.0; taille += 0.2)
    {
        glutWireCube(taille);
    }
    glPopMatrix();
}

void freeMemories()
{
    if(matrice != NULL)
    {
        for(int i = 0; i < nbColumns; i++)
        {
            delete [] matrice[i];
        }
        delete [] matrice;
    }
}

void gameOver()
{
    if(firstPlayer.getPosX() == endX && 
        firstPlayer.getPosY() == endY)
        {
            cout << "Bravo !!! vous etes sorti du labyrinthe" << endl;
            labyAffichage();
            freeMemories();
            exit(1);
        }
}