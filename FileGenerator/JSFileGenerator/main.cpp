#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>	

#include "config.cpp"

using namespace std;


/*string addDate(){
	std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    return (now->tm_year + 1900) + '-' 
         + (now->tm_mon + 1) + '-'
         +  now->tm_mday;
}*/

void askQuestion(string &n, const string &subjectQ){
	bool isOk = false;
	string yn = "";
	string inp;
		//name dev
		while(!isOk){
			cout << subjectQ << " ?" << endl;
			getline(cin, inp);
			
			bool responseYN = false;
			while(!responseYN){
				cout << subjectQ << " is correct : " << inp << " Y/n" << endl;
				getline(cin, yn);
				
				if(yn == "Y" || yn == "yes" || yn == "y")
					isOk = true, responseYN = true, n = inp;
				else if(yn == "N" || yn == "no" || yn == "n")
					responseYN = true,cout << "Repeat operation" << endl;
				else				
					cout << "write Y for yes or N for no" << endl;
			}
				
		}
}
void open_and_replace(const string &nameFile, vector<string> strs, const string &folder, const string &tplName, string typeFile = ".js"){
	ifstream fileIn(nameFile.c_str());
	if(fileIn.is_open()){
		cout << "Open " << nameFile << " for create your file.js" << endl;
		string lines;
		
		for(char ch; fileIn.get(ch); lines.push_back(ch));
		for(int i = 0; i < strs.size(); ++i){
			auto pos = lines.find(strs[i]);
			while( pos != std::string::npos){
				lines.replace(pos, strs[i].length(), tplName);
				pos = lines.find(strs[i]);
			}		
		}
		
		cout << "Register your file in : " << folder+tplName << typeFile << endl;
		ofstream fileout(folder+tplName+typeFile);
        fileout << lines;
		fileIn.close();
	}else{
		cout << "Error: path or file for write Template doesn't exists" << endl;
	}
}
int main(int argc, char **argv)
{
	string const FileJS = PATH_WHERE_FILES+"Template.js";
	string const FileHTML = PATH_WHERE_FILES+"Template.html";
	
	string name;
	string folder;
	string tplName;
	
	
	//check if argv input
	if(argc > 1){
		name = argv[1]; //name dev
		tplName = argv[2]; //name tpl
		folder = argv[3]; //root folder for send created files
	}else{
		bool isOk = false;
		//name dev
		askQuestion(name, "Name");
		
		//name template
		askQuestion(tplName, "Template name");
		
		//path for send files output
		askQuestion(folder, "What is root folder where send files created ?");
	}
	
	//open html/js file
	open_and_replace(FileJS, {TPL, NAME}, folder, tplName);
	open_and_replace(FileHTML, {TPL}, folder, tplName, ".html");	
	
	return 0;			
}
