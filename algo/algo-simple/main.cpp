#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

class CombinationArray{
private:
	static CombinationArray m_instance;
	CombinationArray& operator= (const CombinationArray&){return *this;};
	void combinationUtil(vector<string>& arr, vector<string>& datas, int start, int end, int index, int r, map<int, vector<string> >& allCombi);
	void removeDuplicate(vector<string> arr);
public:
	static CombinationArray& Instance();
	CombinationArray();
	~CombinationArray();
	static void chooseCombinations(vector<string>& arr, int r, map<int, vector<string> >& allCombi);
	static void allCombinations(vector<string>& arr, map<int, vector<string> >& allCombi);
};

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

CombinationArray CombinationArray::m_instance=CombinationArray();
CombinationArray& CombinationArray::Instance(){
	return m_instance;
};

CombinationArray::CombinationArray(){

	cout << "CombinationArray created" << endl;
};

CombinationArray::~CombinationArray(){
	cout << "CombinationArray destroyed" << endl;
};

void CombinationArray::combinationUtil(vector<string>& arr, vector<string>& datas, int start, int end, int index, 
		int r, map<int, vector<string> >& allCombi){

	if(index == r){
		string a = "";
		vector<string> vtr;
		map<int, vector<string> >::iterator it = allCombi.find(r);
		if(it != allCombi.end())
			vtr = allCombi[r];

		for(int j = 0; j < r; j++)
			a += datas[j]+" ";
		
		vtr.push_back(a);
		allCombi[r] = vtr;
	}

	for(int i = start; i <= end && end-i+1 >= r-index; i++){
		datas.insert(datas.begin()+index,arr[i]);
		this->combinationUtil(arr, datas, i+1, end, index+1, r, allCombi);
	}
}

void CombinationArray::chooseCombinations(vector<string>& arr, int r, map<int, vector<string> >& allCombi){
	CombinationArray& ptr = CombinationArray::Instance();

	vector<string> data;

	sort(arr.begin(), arr.end());

	int n = arr.size();

	if(r > n)
		return ;

	if(r < 0)
		return ;

	ptr.combinationUtil(arr, data, 0, n-1, 0, r, allCombi);
}

void CombinationArray::allCombinations(vector<string>& arr, map<int, vector<string> >& allCombi){
	CombinationArray& ptr = CombinationArray::Instance();

	vector<string> data;

	sort(arr.begin(), arr.end());

	int n = arr.size();

	for(int i = 0; i <= n; i++)
		ptr.combinationUtil(arr, data, 0, n-1, 0, i, allCombi);

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
