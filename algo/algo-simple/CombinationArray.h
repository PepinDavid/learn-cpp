#ifndef DEF_COMBINATIONARRAY
#define DEF_COMBINATIONARRAY

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

#endif
