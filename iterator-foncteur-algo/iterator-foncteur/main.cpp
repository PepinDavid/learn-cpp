#include <stdio.h>
#include <cctype>
#include <cstdlib> //pour rand()                                                     
#include <ctime>   //pour time() 
#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <map>

using namespace std;
foncteur baisc
class Addition{
public:
	int operator()(int a, int b){
		return a+b;
	}
};
class FindVoyelles{
public:
	int operator()(string const &str){
		unsigned int i = 0, cpt = 0;
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
                    cpt++;  
                default:
                    break;        
            }
		}
		return cpt;
	}
};
class SortStringMap{
public:
	bool operator()(const string &a, const string &b){
		return a.size() < b.size();
	}
};
//foncteur evolutif
class RemplirVector{
public:
	RemplirVector(int i) :m_value(i){}
	int operator()(){
		return m_value;
	}
private:
	int m_value;
};
class RemplirVectorRandom{
public:
	RemplirVectorRandom():m_value(){}
	
	int operator()(){
		m_value = rand()%10; 
		return m_value;
	}
private:
	int m_value;
};
void seeVector(std::vector<int> const &arr) {
	std::cout << arr.size() << std::endl;
	for(auto const &i: arr)
		std::cout << i << " | ";
	std::cout << "\n\n" << std::endl;
}

int main() {
	srand(time(0));
	//ITERATOR
	cout << "ITERATOR exemple on vector and map" << endl;
	vector<int> arr = {5, 7, 9, 2, 4};
	//old school: vector<int>::iterator it = arr.begin();
	auto it = arr.begin();
	
	map<string, double> mArr = {{"souris", 0.05}, {"tigre", 200}, {"chat", 3}, {"elephant", 10000}};
	//old school: map<string, double>::iterator it = mArr.begin();
	auto mapIt = mArr.begin();
	for(; it != arr.end(); ++it)
		cout << *(it) << " | ";
	
	
	cout << "arr.begin()+2 : ";
	it = arr.begin()+2;
	cout << *(it) << endl;
	
	for(; mapIt != mArr.end(); ++mapIt)
		cout << mapIt->first << " : " << mapIt->second << " kg" << endl;
		
	cout << "mArr.begin()+1 : ";
	mapIt = mArr.begin();
	mapIt++;
	cout << mapIt->first << " : " << mapIt->second << " kg" << endl;
	
	cout << "finish ITERATOR \n\n\n" << endl;
	
	//FONCTEUR BASIC
	cout << "FONCTEUR BASIC exemple addition de deux int" << endl;
	int x = 2, y = 5;
//on peut le déclarer ou l'utiliser directement
	//utilisation comme fonction;
	cout << x << " + " << y << " = " << Addition(x,y) << endl;
	
	cout << "FONCTEUR BASIC exemple comptage de char dans une string" << endl;
	string s;
	//avec declaration
	FindVoyelles f;
	cout << "Ecrire une phrase " << endl;
	getline(cin, s);
	
	cout << "Il y a " << f(s) << " voyelles dans votre phrase : \n \t";
	cout << s << endl;
	
	cout << "FONCTEUR BASIC exemple trie map<string,double> dans l'ordre croissant longueur de string" << endl;
	map<string, double, SortStringMap> mapPoids = {{"souris", 0.05}, {"tigre", 200}, {"chat", 3}, {"elephant", 10000}};
	auto poidIt = mapPoids.begin();
	//old school
	cout << "loop iterator" << endl;
	for(; poidIt != mapPoids.end(); ++poidIt)
		cout << poidIt->first << " : " << poidIt->second << " kg" << endl;
	
	cout << "modern loop" << endl;
	for(auto pet: mapPoids)
		cout << pet.first << " : " << pet.second << " kg" << endl;
	
	cout << "FONCTEUR EVOLUTIF remplissage avec une valeur identique pour toutes les cases" << endl;

	vector<int> tab(50, -1);
	cout << " init vector a -1 pour toutes les cases " << endl;
	seeVector(tab);
//de la meme manier on peut l'utiliser directement en fonction ou le déclarer
	cout << " remplissage avec random " << endl;
	for(auto &i: tab)
		i = RemplirVectorRandom();
	seeVector(tab);
	
	RemplirVector g(10);
	for(auto &i: tab)
		i = g();
	seeVector(tab);
	
	cout << "finish FONCTEUR \n\n\n" << endl;
	getchar();//pour system pause
	return 0;
}
