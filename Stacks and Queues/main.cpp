#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;
Stack myStack = Stack();

bool isFirstHalfAllOpeningBrackets(string brackets){
    if (brackets.length() % 2 == 0){
        for (int i = 0; i < brackets.length() / 2; i++){
            if (brackets[i] == ')' || brackets[i] == '}' || brackets[i] == ']'){
                return false;
            }
        }
        return true;
    }
    return false;
}

bool isEnclosed(string brackets){
    myStack.clear();
    if(!isFirstHalfAllOpeningBrackets(brackets)){
        return false;
    }
    for (int i = 0; i < brackets.length(); i++){
        if (brackets[i] == '(' || brackets[i] == '{' || brackets[i] == '['){
            myStack.push(brackets[i]);
        }
        else if (brackets[i] == ')' || brackets[i] == '}' || brackets[i] == ']'){
            if(myStack.isEmpty()){
                return false;
            }
            char c = myStack.top();
            if (( c != '(' && brackets[i] == ')' ) || ( c != '{' && brackets[i] == '}' ) || ( c != '[' && brackets[i] == ']' )){
                return false;
            }
            myStack.pop();
        }
    }
    return true;
}

int main() {
    string brackets;

    while (true){
        cin >> brackets;
        if(brackets.compare("q")==0){
            break;
        }
        if (isEnclosed(brackets)){
            cout << brackets << " brackets are enclosed."<<endl;
        }else {
            cout << brackets << " brackets are not enclosed."<<endl;
        }
    }
    return 0;
}