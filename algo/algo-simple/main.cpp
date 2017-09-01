#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

#include "CombinationArray.h"
using namespace std;


int PGCD(int a, int b);

int main(int argc, char **argv)
{
	printf("hello world\n");
	vector<string> abc;
	abc.push_back("a");
	abc.push_back("b");
	abc.push_back("c");

	map<int, vector<string> > sol;

	cout << "combination finished " << endl;

	vector<string> s = {"a", "b", "c"};

	CombinationArray::allCombinations(s, sol);
	for(auto& ins : sol){
		cout << ins.first << " : " << endl;
		for(int j = 0; j < ins.second.size(); j++)
			cout << "\t" << ins.second[j] << endl;
	}

	sol.erase(sol.begin(), sol.end());
	CombinationArray::chooseCombinations(s, 2, sol);
	for(auto& ins : sol){
		cout << ins.first << " : " << endl;
		for(int j = 0; j < ins.second.size(); j++)
			cout << "\t" << ins.second[j] << endl;
	}
	cout << PGCD(123, 27) << endl;
	cout << PGCD(27, 123) << endl;
	return 0;
}

int PGCD (int a, int b){
	if(b > a){
		int temp = a;
		a = b;
		b = temp;
	}
	int q = a / b;
	int r = a - (b * q);

	if(r == 0)
		return b;
	else
		return PGCD(b, r);

}
