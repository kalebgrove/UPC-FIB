/* reverseSubstring

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include <iostream>
#include <string>

using namespace std;

// Pre: 0 <= i <= j < s.size()
// Post: el substring s[i..j] s'ha revessat. La resta de s no ha canviat.
void reverseSubstring(string &s, int i, int j){
    //Base case:
    if(i >= j) return;

    char c = s[i];
    s[i] = s[j];
    s[j] = c;

    reverseSubstring(s, i+1, j-1);
}

int main() {
    string s;
    cin >> s;

    int n, m;
    cin >> n >> m;

    reverseSubstring(s, n, m);
    cout << s << endl;
}