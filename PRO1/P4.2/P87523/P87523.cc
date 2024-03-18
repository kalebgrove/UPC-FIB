#include <iostream>

using namespace std;

int main() {
    char c;
    cin >> c;
    char c1 = '-', c2 = '-', c3 = '-', c4 = '-';
    bool hello = false;

    while(not hello and c != '.') {
        if(c4 == 'h' and c3 == 'e' and c2 == 'l' and c1 == 'l' and c == 'o') hello = true;
        
        c4 = c3;
        c3 = c2;
        c2 = c1;
        c1 = c;

        cin >> c;
    }
    if(hello) cout << "hello\n";
    else cout << "bye\n";
}

/*int main() {
    char c;
    cin >> c;

    bool hello = false;

    while(c != '.' and not hello) {
        if(c == 'h') {
            cin >> c;
            if(c == 'e') {
                cin >> c;
                if(c == 'l') {
                    cin >> c;
                    if(c == 'l') {
                        cin >> c;
                        if(c == 'o') {
                            hello = true;
                        }
                    }
                }
            }
        } else {
            cin >> c;
        }
    }
    if(hello) cout << "hello\n";
    else cout << "bye\n";
    
}*/