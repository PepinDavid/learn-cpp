#include "Player.h"

using namespace std;

Player::Player(int x, int y, bool q) : Perso(x, y)
{
    m_name = new char[25];
    if(q){
        cout << "Quel est votre nom ? " << endl;
        cin >> ws;//ws est un manipulateur de cin, il permet de ne pas
        //s'arrete aux blanks dans les chaines de caractere;
        cin.get(m_name, 25);

        //Vidage de la memoire tampon
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }else{
        m_name = "Héro";
    }
    cout << "Welcome in the game " << m_name << endl;
    cout << "Player créé" << endl;
}

Player::~Player()
{
    //call destructor if class create by pointer ?!
//    if(m_name != NULL)
//        delete m_name;
}

void Player::getName()
{
    cout << "nom du player : " << m_name << endl;
    cout << "* : " << * m_name << endl;
    cout << "[0] : " << m_name[0] << endl;
    cout << "& : " << &m_name << endl;
}

void Player::draw()
{
    glPushMatrix();
    
    glTranslated(m_posX+0.5, m_posY+0.5, 0.0);
    glColor3d(1.0, 1.0, 0.0); //jaune
    glutSolidSphere(0.3, 12, 12); // sphere de la ete
    
    glTranslated(0.1, -0.1, 0.0);
    glColor3d(0.0, 0.0, 0.0); //couleur noir
    glutSolidSphere(0.05, 12, 12); //1ere oeil
    glTranslated(-0.2, 0.0, 0.0);
    glutSolidSphere(0.05, 12, 12); //2eme oeil
    
    glPopMatrix();
}