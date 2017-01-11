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
//pour faire un pendu ?
//void createUnderScoreWord(int const s, string& under){
//	for(int i = 0; i < s; ++i){
//		under += "_";
//	}
//}
//void replaceUnderScoreWord(string& goodS, string& under, string& answer){
//	for(int i = 0; i < goodS.size(); ++i){
//		for(int j = 0; j < answer.size(); ++j){
//			if(goodS[i] == answer[j]){
//				cout << answer[j] << endl;
//				under[i] = answer[j];
//			}
//				
//		}
//	}
//}
//jeu version code simple
void playWithoutFile(string wordClear = "")
{
    string wordMystery, wordResp(""), blanck;
    int cpt(10);
    srand(time(0));
    if(wordClear.size() < 1)
    {
        cout << "Ecrire a un mot  : " << endl;
        cin >> wordClear;
        system("clear");
    }
	
    wordMystery = mixWord(wordClear);
	//createUnderScoreWord(wordClear.size(), blanck);
    do
    {
		cout << "Il vous reste " << cpt << "coups" << endl;
        cout << " Quel est ce mot : " << wordMystery << endl;
		//cout << " Lettre decouverte : " << blanck << endl;
        cin >> wordResp;
        cpt--;
		//replaceUnderScoreWord(wordClear, blanck, wordResp);
        if(wordClear != wordResp)
        {
            cout << "Ce n'est pas le bon mot !" << endl;
        }

    }while(wordClear != wordResp && cpt > 0); // pour le pendu && wordClear == blanck
	if(cpt < 1)
		cout << "Désolé, vous avez perdu, le mot mystère etait : " << wordClear << endl;
	else
		cout << "Bravo c'est gagné !!! Vous avez fait ça en : " << cpt << " coups " << endl;
}


string getWordFile(string s)
{
    string word("");
    vector<string> listWord;
    ifstream wordFile(s.c_str());
    int nb(0);
    if(wordFile)
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
        cout << "ERREUR le fichier demandé n'existe pas " << endl;
		return word;
    }
}

//jeu version code avec prise d'un mot dans une liste de mots dans un fichier.
void playWithFile()
{
    srand(time(0));
    string word, path;
	cout << "Entre le chemin et le nom du fichier pour jouer" << endl;
	cin >> path;

    word = getWordFile(path);
    playWithoutFile(word);
}

int main()
{
    bool again(true);
    string replay(""), file;
    int play(1);
    while(again){
        cout << "Bienvenue sur le jeu mystère ! " << endl;
		cout << "Jouez avec un fichier ? (yes/no)" << endl;
		cin >> file; cin.ignore();
		if(file == "oui" || file == "yes")
        {
            playWithFile();
        }else{
			playWithoutFile();
		}        
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
            default:
                cout << "Veuillez répondre par yes ou no" << endl;
        }
    }
    return 0;
}
