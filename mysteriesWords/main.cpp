#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

//fonction qui sert a mélanger un mot
string mixWord(string s)
{
    string mixed;
    int position(0);

    while(s.size() != 0)
    {
        position = rand() % s.size();

        mixed += s[position];

            s.erase(position, 1);
    }

    return mixed;
}

//jeu version code simple
void playWithoutFile(string wordClear = "")
{
    string wordMystery, wordResp("");
    int cpt(0), gameover(5);
    srand(time(0));
    if(wordClear.size() < 1)
    {
        cout << "Ecrire a un mot  : " << endl;
        cin >> wordClear;
        system("clear");
    }

    wordMystery = mixWord(wordClear);
    do
    {
        cout << " Quel est ce mot : " << wordMystery << endl;
        cin >> wordResp;
        cpt++;

        if(wordClear != wordResp)
        {
            cout << "Ce n'est pas le bon mot ! " << endl;
            gameover--;
            cout << "Reste " << gameover << "coups" << endl;
        }

    }while(wordClear != wordResp && gameover > 0);

    if(gameover > 0){
        cout << "Bravo c'est gagné !!! Vous avez fait ça en : " << cpt << " coups " << endl;
    }else{
        cout << "Désole c'est game over! Le mot mystères est : " << wordClear << endl;
    }
}

string getWordFile(string s)
{
    string word("");
    vector<string> listWord;
    ifstream wordFile(s.c_str());
    int nb(0);

    if(wordFile.is_open())
    {
        while(getline(wordFile, word))
        {
            listWord.push_back(word);
        }
        nb = rand() % listWord.size();

        return listWord[nb];
    }
    else
    {
        cout << "ERREUR le fichier demandé n'existe pas ";
        return word;
    }
}


//jeu version code avec prise d'un mot dans une liste de mots dans un fichier.
void playWithFile()
{
    srand(time(0));
    string word, path("/home/david/dev/learn-cpp/mysteriesWords/words.txt");

    word = getWordFile(path);

    playWithoutFile(word);
}

int main()
{
    bool again(true);
    string replay("");
    int play(2);
    while(again){
        cout << "Bienvenue sur le jeu mystère ! " << endl;
        //playWithoutFile();
        playWithFile();
        cout << "Vouez vous rejouer ? (yes/no)" << endl;
        cin >> replay;
        if(replay == "oui" || replay == "yes")
        {
            play = 1;
        }
        else if(replay == "non" || replay == "no")
        {
            play = 0;
        }
        switch(play)
        {
            case 1:
                break;
            case 0:
                again = false;
                break;
            case 2:
                cout << "Veuillez répondre pour yes ou no" << endl;
                break;
        }
    }
    return 0;
}