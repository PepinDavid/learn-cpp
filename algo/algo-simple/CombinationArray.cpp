#include "CombinationArray.h"

using namespace std;


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
