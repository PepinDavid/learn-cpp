#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

//fonction qui sert a mélanger un mot
void mixWord(string s, string &mixed)
{
    int position(0);
    while(s.size() != 0)
    {
        position = rand() % s.size();

        if((int)s[position] != 13)
            mixed += s[position];
        s.erase(position, 1);
    }
}
bool compareResp(const string clear,const string resp){
    for(int i = 0; i < clear.size()-1; ++i){
        if(clear[i] != resp[i])
            return true;
    }
    return false;
}
//jeu version code simple
void playWithoutFile(string &wordClear)
{
    string wordMystery = "", wordResp = "";
    int gameover(5);
    srand(time(0));
    if(wordClear.size() < 1)
    {
        cout << "Ecrire a un mot  : " << endl;
        cin >> wordClear; cin.ignore();
        system("clear");
    }

    mixWord(wordClear, wordMystery);
    //for the response
    cout << wordClear << endl;
    do
    {
        cout << "Quel est ce mot : " << endl;
        cout << wordMystery << endl;
        cin >> wordResp; cin.ignore();
        gameover--;
        if(compareResp(wordClear, wordResp)){
            cout << "Ce n'est pas le bon mot ! " << endl;
            cout << "Reste " << gameover << " coups" << endl;
        }

    }while(compareResp(wordClear, wordResp) && gameover > 0);

    if(gameover > 0){
        cout << "Bravo c'est gagné !!! Vous avez fait ça en : " << 5 - gameover << " coups " << endl;
    }else{
        cout << "Désole c'est game over! Le mot mystères est : " << wordClear << endl;
    }
}

string getWordFile(char*  &s)
{
    string word = "";
    vector<string> listWord;
    ifstream wordFile(s);
    int nb = 0;

    if(wordFile.is_open()){
        while(getline(wordFile, word))
        {
            listWord.push_back(word);
        }
        nb = rand() % listWord.size();

        return listWord[nb];
    }else{
        cout << "ERREUR le fichier demandé n'existe pas ";
        return word;
    }
}


//jeu version code avec prise d'un mot dans une liste de mots dans un fichier.
void playWithFile(char* &path)
{
    string word = "";
    word = getWordFile(path);

    playWithoutFile(word);
}

int main()
{
    bool again(true);
    string replay("");
    char *path = "/home/david/dev/learn-cpp/mysterieWords/mysteriesWords/dico.txt";
    int play(2);
    srand(time(0));
    while(again){
        cout << "Bienvenue sur le jeu mystère ! " << endl;
        //playWithoutFile();
        playWithFile(path);
        cout << "Vouez vous rejouer ? (yes/no)" << endl;
        cin >> replay;
        if(replay == "oui" || replay == "yes")
            play = 1;
        else if(replay == "non" || replay == "no")
            play = 0;
            
        switch(play){
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
