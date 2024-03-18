#include <iostream>
#include <vector>

using namespace std;

typedef vector<char> VC;

bool found(int length, string s, string word) {
    if(s.size() < word.size()) return false;
    int j = 0;
    for(int i = 0; i < length; ++i) {
        if(word[j] == s[i]) {
            ++j;
            if(j == word.size()) return true;
        } else {
            i = i - j;
            j = 0;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<string> s(n);

    for(int i = 0; i < n; ++i) cin >> s[i];

    for(int i = 0; i < n; ++i) {
        cout << s[i] << ':';

        for(int j = 0; j < n; ++j){ // This loop is meant to cycle through all of the words and try to find the ones that fit inside s[i].
            int length = s[i].size();

            if(found(length, s[i], s[j])) {
                    cout << ' ' << s[j];
            }
        }
        cout << endl;
    }
}