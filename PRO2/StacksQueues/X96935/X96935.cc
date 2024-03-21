/* Palíndroms amb piles

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> s;

    int x;
    int i = 0;
    while(i < n/2) {
        cin >> x;
        s.push(x);
        ++i;
    }

    if(n%2 == 1) {
        cin >> x;
        ++i;
    }

    bool palindrome = true;
    while(i < n and palindrome) {
        cin >> x;
        if(x != s.top()) palindrome = false;
        s.pop();
        ++i;
    }

    if(not palindrome) cout << "NO" << endl;
    else cout << "SI" << endl;
}