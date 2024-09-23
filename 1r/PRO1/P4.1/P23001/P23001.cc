#include <iostream>

using namespace std;

int main() {
    string word, word2;
    cin >> word >> word2;
    int count = 1, count2 = 0;
    if(word2 == word){
        count = 2;
        count2 = 2;
    }

    while(cin >> word2) {
        if(word2 == word) {
            ++count2;
        } else {
            count2 = 0;
        }
        if(count < count2) count = count2;
    }
    cout << count << endl;
}