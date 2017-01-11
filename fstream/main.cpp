#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void readAll(string s)
{
    ifstream file(s.c_str());

    if(file.is_open())
    {
        string line;
        while(getline(file, line))
        {
            cout << line << endl;
        }

    }
    else
    {
        cout << "Error: impossible to open this file : " << file << endl;
    }
}

void searchWord(string s)
{
    ifstream file(s.c_str());
    int countWord(0);
    string line, word;

    if(file.is_open())
    {
        cout << "Quel mot cherché vous ? " << endl;
        cin >> word;
        while(file >> line)
        {
            if(word.compare(line) == 0 )
            {
                countWord++;
            }
        }
        cout << "Votre mot a été trouvé " << countWord << " fois " << endl;
    }
    else
    {
        cout << "Error: impossible to open this file : " << file << endl;
    }
}

int main()
{
    string const text("/home/david/dev/c++/fstream/text.txt");
    string const text2("/home/david/dev/c++/fstream/text2.txt");
    string answer("");
    int age(28);

    //ecriture dans des fichier
    ofstream flowWrite(text.c_str()); // ouverture d'un flux en ecriture mais fait ça ecrase le fichier pour le remplacer !!!
    ofstream flowTwoWrite(text2.c_str(), ios::app); // avec ios(namespace de fstream) app ça ecrit a la fin du fichier !!!


    if(flowWrite)
    {
        flowWrite << "Bonjour, je suis une pharse de test d'écriture ." << endl;
        flowWrite << " un peu de nombre : " << 42.35486 << endl;
        flowWrite << "J'ai " << age << " ans ." << endl;
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
    if(flowTwoWrite)
    {
        flowTwoWrite << "Bonjour, moi c'est Léon le roi du camion." << endl;
        cout << "un truc a dire ? " << endl;
        getline(cin, answer);
        flowTwoWrite << answer << endl;
        flowTwoWrite << "c'est la fin du message" << endl;
    }

    //lecture dans des fichiers
    ifstream flowRead(text.c_str());
    ifstream flowTwoRead(text2.c_str());
    string mot, ligne;
    char lettre;
    if(flowRead)
    {
        cout << "Lecture d'un mot " << endl;
        flowRead >> mot; // lecture d'un mot
        cout << mot << endl;
        flowRead.ignore(); //on change de mode de lecture

        cout << "Lecture d'une phrase " << endl;
        getline(flowRead, ligne); // on lit une phrase;
        cout << ligne << endl;
        flowRead.ignore(); //on change de mode de lecture

        cout << "Lecture d'un caractère " << endl;
        flowRead.get(lettre); // lecture d'un mot
        cout << lettre << endl;
        flowRead.ignore(); //on change de mode de lecture

        cout << "fin ! " << endl;
    }

    //readAll(text2);
    searchWord(text2);
    return 0;
}
