#include <iostream>
#include <vector>

using namespace std;

int numberSubsequences(const string &s, char c1, char c2, char c3) {
    int ctr = 0, ctr2 = 0, ctr3 = 0;
    
    /*for(int i = 0; i < s.size(); ++i) {
        if(s[i] == c1) {
            for(int j = i+1; j < s.size(); ++j) {
                if(s[j] == c2) {
                    for(int k = j+1; k < s.size(); ++k) {
                        if(s[k] == c3) ++sum;
                    }
                }
            }
        }
    }*/

    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == c1) ++ctr;
        else if(s[i] == c2) ctr2 += ctr;
        else if(s[i] == c3) ctr3 += ctr2;
    }

    return ctr3;
}

int numberHappySubsequences(const string &s) {

    return numberSubsequences(s, '(', '-', ':') + numberSubsequences(s, ':', '-', ')');
}

int numberSadSubsequences(const string &s) {

    return numberSubsequences(s, ')', '-', ':') + numberSubsequences(s, ':', '-', '(');
}


int main() {
    string s;

    while(cin >> s) {
        cout << numberHappySubsequences(s) << ' ' << numberSadSubsequences(s) << endl;
    }
}