#include <iostream>
#include <vector>

using namespace std;

const int length_alphabet = 'z' - 'a' + 1;

char most_frequent_letter(const string& s) {
    vector<int> freq(length_alphabet, 0);
    int max = 0;
    char c = s[0];

    for(int i = 0; i < s.size(); ++i) {
        ++freq[s[i] - 'a'];
    }

    for(int i = 0; i < length_alphabet; ++i) {
        if(max < freq[i]) {
            max = freq[i];
            c = char(i + 'a');
        }
    }
    return c;
}

int main() {
    cout.setf(ios::fixed);
    cout.precision(2);

    int n;
    cin >> n;

    string s;
    double sum = 0;

    vector<string> w(n);
    vector<char> c(n);

    for(int i = 0; i < n; ++i) {
        cin >> s;
        c[i] = most_frequent_letter(s);
        sum += s.size();
        w[i] = s;
    }

    cout << sum/n << endl;

    for(int i = 0; i < n; ++i) {
        if(w[i].size() >= sum/n) cout << w[i] << ": " << c[i] << endl;
    }
}