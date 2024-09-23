#include <iostream>

using namespace std;

int main() {
    int num1, num2, num3;
    char oper;
    string comp;
    
    int result;
    string answer = "false";
    
    while (cin >> num1 >> oper >> num2 >> comp >> num3) {
        
        if(oper == '-') {
            result = num1 - num2;
            if((comp == ">") and (result > num3)) answer = "true";
            if((comp == ">=") and (result >= num3)) answer = "true";
            if((comp == "<") and (result < num3)) answer = "true";
            if((comp == "<=") and (result <= num3)) answer = "true";
            if((comp == "==") and (result == num3)) answer = "true";
            if((comp == "!=") and (result != num3)) answer = "true";
        } else if(oper == '+') {
            result = num1 + num2;
            if((comp == ">") and (result > num3)) answer = "true";
            if((comp == ">=") and (result >= num3)) answer = "true";
            if((comp == "<") and (result < num3)) answer = "true";
            if((comp == "<=") and (result <= num3)) answer = "true";
            if((comp == "==") and (result == num3)) answer = "true";
            if((comp == "!=") and (result != num3)) answer = "true";
        } else if(oper == '*') {
            result = num1*num2;
            if((comp == ">") and (result > num3)) answer = "true";
            if((comp == ">=") and (result >= num3)) answer = "true";
            if((comp == "<") and (result < num3)) answer = "true";
            if((comp == "<=") and (result <= num3)) answer = "true";
            if((comp == "==") and (result == num3)) answer = "true";
            if((comp == "!=") and (result != num3)) answer = "true";
        }
        cout << answer << endl;
        answer = "false";
    }
}