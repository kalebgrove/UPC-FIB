#include <iostream>

using namespace std;

int main() {
    char first, second, third;
    int aaa = 0, aab = 0, aba = 0, abb = 0, baa = 0, bab = 0, bba = 0, bbb = 0;
    int cnt = 0;
    bool found = false;
    cin >> first >> second >> third;

    while(not found) {
        if(first == 'a' and second == 'a' and third == 'a') ++aaa;
        if(first == 'a' and second == 'a' and third == 'b') ++aab;
        if(first == 'a' and second == 'b' and third == 'a') ++aba;
        if(first == 'a' and second == 'b' and third == 'b') ++abb;
        if(first == 'b' and second == 'a' and third == 'a') ++baa;
        if(first == 'b' and second == 'a' and third == 'b') ++bab;
        if(first == 'b' and second == 'b' and third == 'a') ++bba;
        if(first == 'b' and second == 'b' and third == 'b') ++bbb;

        if(aaa == 2 or aab == 2 or aba == 2 or abb == 2 or baa == 2 or bab == 2 or bba == 2 or bbb == 2){
            found = true;
            cout << first << second << third << ' ' << cnt << endl;
        } 
        else {
            ++cnt;
            first = second;
            second = third;
            cin >> third;
        }
    }
}