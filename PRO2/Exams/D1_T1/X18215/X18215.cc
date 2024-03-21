#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Pre: all holds true.
//Post: returns true if a rule has been applied.
bool apply_rules(vector<char>& code, char& next) {
    int size = code.size();        
    if(code[size-1] == 'n') {
        code[size-1] = 'E';
        return true;
    } else if(code[size-1] == 'v' and next != '=') {
        code[size-1] = 'E';
        return true;

    } else if(size >= 3 and code[size-3] == 'E' and code[size-2] == '*' and code[size-1] == 'E') {
        code[size-3] = 'E';
        code.resize(size-2);
        return true;

    } else if(size >= 3 and code[size-3] == 'E' and code[size-2] == '+' and code[size-1] == 'E' and next != '*') {
        code[size-3] = 'E';
        code.resize(size-2);
        return true;

    } else if(size >= 3 and code[size-3] == 'E' and code[size-2] == '<' and code[size-1] == 'E' and next != '*' and next != '+') {
        code[size-3] = 'E';
        code.resize(size-2);
        return true;

    } else if(size >= 4 and code[size-4] == 'v' and code[size-3] == '=' and code[size-2] == 'E' and code[size-1] == ';') {
        code[size-4] = 'I';
        code.resize(size-3);
        return true;

    } else if(size == 3 and code[size-3] == '(' and code[size-2] == 'E' and code[size-1] == ')') {
        code[size-3] = 'E';
        code.resize(size-2);
        return true;

    } else if(size >= 4 and code[size-4] != 'i' and code[size-4] != 'w' and code[size-3] == '(' and code[size-2] == 'E' and code[size-1] == ')') {
        code[size-3] = 'E';
        code.resize(size-2);
        return true;

    } else if(size >= 5 and code[size-5] == 'i' and code[size-4] == '(' and code[size-3] == 'E' and code[size-2] == ')' and code[size-1] == 'I' and next != 'e') {
        code[size-5] = 'I';
        code.resize(size-4);
        return true;

    } else if(size >= 7 and code[size-7] == 'i' and code[size-6] == '(' and code[size-5] == 'E' and code[size-4] == ')' and code[size-3] == 'I' and code[size-2] == 'e' and code[size-1] == 'I') {
        code[size-7] = 'I';
        code.resize(size-6);
        return true;

    } else if(size >= 5 and code[size-5] == 'w' and code[size-4] == '(' and code[size-3] == 'E' and code[size-2] == ')' and code[size-1] == 'I') {
        code[size-5] = 'I';
        code.resize(size-4);
        return true;

    } else if(size >= 2 and code[size-2] == 'L' and code[size-1] == 'I') {
        code[size-2] = 'L';
        code.resize(size-1);
        return true;
        
    } else if(size >= 2 and code[size-2] != ')' and code[size-2] != 'L' and code[size-1] == 'I') {
        code[size-1] = 'L';
        return true;

    } else if(size == 1 and code[size-1] == 'I') {
        code[size-1] = 'L';
        return true;

    } else if(size >= 3 and code[size-3] == '{' and code[size-2] == 'L' and code[size-1] == '}') {
        code[size-3] = 'I';
        code.resize(size-2);
        return true;
    }

    return false;
}

int main() {
    string program;

//Constantly read the input. No need for getline since I implement strings, not characters.
    while(cin >> program) {
        vector<char> code;

//The for loop is in charge of seperating the string into chars and consecutively storing them in a vector, while applying all possible rules.
        for(int i = 0; i < program.size(); i++) {
            code.push_back(program[i]);
            char next = 'a';
//We want to have a character that hasn't been stored in the vector for ease of applying certain rules.
            if(i+1 < int(program.size())) {
                next = program[i+1];
            }
//While rules are being applied, we execute the function. Therefore, there will be a collapse of the size of the vector since we keep reducing instructions by applying different rules.
            while(apply_rules(code, next));
        }
//Final rule to completely reduce the string into a single character, P, which stands for program.
        if(code[0] == 'L' and code.size() == 1) code[0] = 'P';

//Print the vector.
        for(int i = 0; i < int(code.size()); i++) {
            cout << code[i];
        }
        cout << endl;
    }

}