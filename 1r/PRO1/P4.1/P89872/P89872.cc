#include <iostream>

using namespace std;

int main() {
    string word, min, max;
    cin >> word;
    max = word;
    
    while(cin >> word) {
        if(word > max and word != max and word != min) {
            min = max;
            max = word;
        } else if(word < max and word > min and word != max and word != min) {
            min = word;
        }
    }
    cout << min << endl;
}