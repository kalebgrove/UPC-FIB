#include <iostream>
#include <vector>

using namespace std;

// Pre: two lower-case words; a non-negative integer d
// Post: it returns true if the two words are d-compatible, false otherwise
bool d_compatible(string word1, string word2, int d) {
    if(word1.size() != word2.size()) return false;

    int ctr = 0;
    for(int i = 0; i < word1.size(); ++i) {
        if(word1[i] != word2[i]) ++ctr;
    }
    if(ctr <= d) return true;
    return false;
}

// Pre: a vector v of lower-case words; a lower-case word w; a non-negative integer d
// Post: it returns the first word in v which is d-compatible with w, "--" otherwise
string compatible_word(const vector<string>& words1, string s, int d) {
    for(int i = 0; i < words1.size(); ++i) {
        if(d_compatible(words1[i], s, d)) return words1[i];
    }
    return "--";
}

int main() {
    int d; //Distance d.
    cin >> d;

    int n; //Number of words that we will compare;
    cin >> n;

    vector<string> words1(n);
    for(int i = 0; i < n; ++i) {
        cin >> words1[i];
    }

    string s;
    cin >> s;
    while(s != "STOP") {
        cout << s << ": " << compatible_word(words1, s, d) << endl;
        cin >> s;
    }
}