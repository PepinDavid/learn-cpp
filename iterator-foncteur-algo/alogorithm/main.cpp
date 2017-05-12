#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <cstdlib> //pour rand()                                                     
#include <ctime>   //pour time() 

using namespace std;

//foncteur évolutif
class Remplir{
public:
	Remplir(int i) :m_value(i){}
	int operator()(){
		return m_value;
	}
private:
	int m_value;
};
class RemplirRandom{
public:
	RemplirRandom():m_value(){}
	
	int operator()(){
		m_value = rand()%10; 
		return m_value;
	}
private:
	int m_value;
};
class Somme{
public:
	Somme() : m_somme(0){}
	void operator()(int n){
		m_somme += n;
	}
	int result() const{
		return m_somme;
	}
private:
	int m_somme;
};

//foncteur basic
class Generate
{
public:
    int operator()() const
    {
        return rand() % 10;  //On renvoie un nombre entre 0 et 9
    }
};
class FindVoyelles{
public:
	bool operator()(string const &str){
		unsigned int i = 0;
		for(; i < str.size(); ++i){
			char c = str[i];
			c = tolower(c);
			 switch (c)   
            {
                case 'a':        
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'y':
					return true;
                default:
                    break;        
            }
		}
		return false;
	}
};
class RemplirString{
public:
	string operator()(){
		return "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	}
};
void seeVector(std::vector<int> const &arr) {
	cout << arr.size() << std::endl;
	for(auto const &i: arr)
		std::cout << i << " | ";
	std::cout << "\n\n" << std::endl;
}
void seeVector(std::vector<string> const &arr) {
	std::cout << arr.size() << std::endl;
	for(auto const &i: arr)
		std::cout << i << " | ";
	std::cout << "\n\n" << std::endl;
}
void seeList(std::list<int> const &arr) {
	std::cout << arr.size() << std::endl;
	for(auto const &i: arr)
		std::cout << i << " | ";
	std::cout << "\n\n" << std::endl;
}

int main(int argc, char **argv)
{
	srand(time(0));
	vector<int> arr(50, -1);
	cout << "Exemple avec un vecteur<int>" << endl;
	cout << " init a -1 pour toutes les cases " << endl;
	seeVector(arr);
	
	RemplirRandom f;
	cout << " remplissage avec random " << endl;
	generate(arr.begin(), arr.end(), f);
	seeVector(arr);
	
	cout << "remplissage avec une valeur identique pour toutes les cases" << endl;
	Remplir g(10);
	generate(arr.begin(), arr.end(), g);
	seeVector(arr);
	
	cout << "remplissage avec une valeur alétoire pour les cases 0 a 15 et 30 a 40 " << endl;
	generate(arr.begin(), arr.begin()+15, RemplirRandom());
	generate(arr.end()-20, arr.end()-10, RemplirRandom());
	seeVector(arr);
	
	cout << "sort du vector" << endl;
	sort(arr.begin(), arr.end());
	seeVector(arr);
	
	cout << "calcul de la somme du vector" << endl;
	Somme som;
	som = for_each(arr.begin(), arr.end(), som);
	cout << "total : " << som.result() << "\n\n" << endl;
	
	cout << "cout() avec vector<int>" << endl;
	int const cpt = count(arr.begin(), arr.end(), 5);
	cout << " il y a " << cpt << " fois le chiffre 5 \n\n" << endl;
	
	
	
	cout << "Exemple avec un list<int>" << endl;
	list<int> liste(20, -1);
	cout << " init a -1 pour toutes les cases " << endl;
	seeList(liste);
	
	cout << " remplissage avec random " << endl;
	generate(liste.begin(), liste.end(), f);
	seeList(liste);
	
	cout << "remplissage avec une valeur identique pour toutes les cases" << endl;
	generate(liste.begin(), liste.end(), g);
	seeList(liste);
	
//	//impossible avec une liste
//	cout << "remplissage avec une valeur alétoire pour les cases 0 a 5 et 15 a 20 " << endl;
//	generate(liste.begin(), liste.begin()+5, RemplirRandom());
//	generate(liste.end()-5, liste.end(), RemplirRandom());
//	seeList(liste);
	cout << "calcul de la somme du list<int>" << endl;
	Somme somme;
	somme = for_each(liste.begin(), liste.end(), somme);
	cout << "total : " << somme.result() << "\n\n" << endl;
		
	cout << "cout() avec list<int>" << endl;
	generate(liste.begin(), liste.end(), f);
	int const cptList = count(liste.begin(), liste.end(), 5);
	cout << " il y a " << cptList << " fois le chiffre 5" << endl;
	seeList(liste);
	
	
	
	cout << "Exemple vector<string>" << endl;
	vector<string> stringS(5,"abc");
	cout << "init vector avec 'abc' " << endl;
	seeVector(stringS);
	
	cout << " remplissage avec random " << endl;
	generate(stringS.begin(), stringS.end(), RemplirString());
	seeVector(stringS);
	
	cout << "count des voyelles" << endl;
	int const cptVoyelles = count_if(stringS.begin(), stringS.end(), FindVoyelles());
	cout << "Il y a " << cptVoyelles << " dans le tableau \n\n" << endl;
	
	string str = "ABCabc";
	//old school
		//string::iterator itFindA = find(str.begin(), str.end(), 'a');
	auto itFindA = find(str.begin(), str.end(), 'a');
	if(itFindA == str.end())
		cout << "Lettre 'A' non trouver" << endl;
	else
		cout << "Lettre 'A' trouver" << endl;
	
	getchar();
	return 0;
}
