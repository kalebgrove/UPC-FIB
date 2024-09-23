#include <iostream>
#include <vector>

using namespace std;

void reverse(string s, int n) {
    if(n > 0) {
        cin >> s;
        vector<char> word(s.size());

        for(int i = 0; i < s.size(); ++i) word[i] = s[i];

        reverse(s, --n);

        for(int i = s.size() - 1; i >= 0; --i) cout << word[i];
        cout << endl;
    }
}

int main() {
    int n; 
    cin >> n;
    string s;
    reverse(s, n);
}