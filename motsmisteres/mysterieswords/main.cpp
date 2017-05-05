#include <iostream>
#include <string>
#include <ctime>   //pour utiliser random
#include <cstdlib> //pour utiliser random
#include "utilrecherchemotaleatdico.h"
#include "utilmelangelettresmot.h"
// librairie contenant les fonctionnalites permettant la recherche d un mot aleatoire dans le dictionnaire passe en parametre
using namespace std;
void jouerUneFois(string nomFichierDictionnaire, const int nbEssaisMax, bool & ok) {
    string motAleatoireGenere("");// le mot qui va etre genere aleatoirement par le programme a partir du dictionnaaire
    string motMysterePropose("");
    string reponseJoueur("");
    int nbEssais(0);
    motAleatoireGenere = rechercheMotAleatoireDansFichierDictionnaire(nomFichierDictionnaire, ok);
    bool trouve(false);
    if (ok) {
        melangeMots(motAleatoireGenere, motMysterePropose, ok);
        if (ok) {
            nbEssais = 0;
            cout << "Mot propose : " << motMysterePropose << endl;
            cout << "Vous avez " << nbEssaisMax << " essais pour reconstituer le mot mystere." << endl << endl << endl << endl;
            while (ok && (!trouve) && (nbEssais < nbEssaisMax) ) {
                getline(cin, reponseJoueur);
                trouve = (reponseJoueur == motAleatoireGenere);
                nbEssais++;
                if ((!trouve) && (nbEssais < nbEssaisMax)) {
                    cout << "Reponse fausse : il vous reste " << ( nbEssaisMax - nbEssais ) << " essais." << endl;
                }
            }
            if (!trouve) {
                cout << "La bonne reponse est : " << motAleatoireGenere << endl;
            } else {
                cout << "Bravo, vous avez donne la bonne reponse" << endl;
            }
        }
    }
}
int main()
{
    srand(time(0)); // pour utiliser rand
    const int NB_ESSAIS_MAX_POUR_UN_JEU(5);
    const string emplacementFichierDictionnaire("dico.txt");
    // indique le nom du fichier dictionnaire dans lequel le programme va chercher un mot aleatoire
    // ce fichier doit etre positionne dans le repertoire de lancement par defaut du programme
    bool ok(true);
    bool joueurVeutContinuer(false);
    string ligne("");
    const string reponse1pourcontinuer("O");
    const string reponse2pourcontinuer("o");
    const string reponse3pourcontinuer("0");
    do {
        jouerUneFois(emplacementFichierDictionnaire, NB_ESSAIS_MAX_POUR_UN_JEU, ok);
        cout << "Voulez vous jouer une fois de plus (dans ce cas repondez O ou o ou 0, sinon, donnez n\'importe quelle autre reponse) ?" << endl;
        getline(cin, ligne);
        joueurVeutContinuer = ( (ligne == reponse1pourcontinuer) || (ligne == reponse2pourcontinuer) || (ligne == reponse3pourcontinuer) );
    } while (joueurVeutContinuer);
    if (!ok) {
        cout << "Le programme ne fonctionne pas correctement (probleme technique)" << endl;
        return 1;
    }

    return 0;
}
