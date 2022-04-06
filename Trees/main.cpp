#include <iostream>
#include<vector>
#include "Library.h"
using namespace std;

void SplitString(string s, vector<string> &v){

    string temp = "";
    for(int i=0;i<s.length();++i){

        if(s[i]==' '){
            v.push_back(temp);
            temp = "";
        }
        else{
            temp.push_back(s[i]);
        }

    }
    v.push_back(temp);

}

int main() {
    string operation;
    Library library = Library();
    getline(cin, operation);
    while(true)
    {
        vector<string> v;
        SplitString(operation, v);
        if(v.size() == 1){
            if(stoi(v[0])==-1){
                exit (0);
            }
            library.clear();
        }
        else if(v.size() == 2 && library.getRoot() != nullptr){
            cout << library.subtreeRootIdSearch(library.getRoot(),stoi(v[0]),stoi(v[1])) << endl;
        }
        else{
            for (int i = 0; i < v.size(); i++){
                library.insert(stoi(v[i]));
            }
        }
        getline(cin, operation);
    }

    return 0;
}
