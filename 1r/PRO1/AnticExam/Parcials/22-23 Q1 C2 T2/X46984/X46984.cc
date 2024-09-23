#include <iostream>
#include <vector>

using namespace std;

bool valid(string password, int n, int m, char s) {
    int ctr = 0;
    for(int i = 0; i < password.size(); ++i) {
        if(s == password[i]) ++ctr;
    }
    if(ctr >= n and ctr <=m) return true;
    return false;
}

int main() {
    int p; //Number of passwords.
    cin >> p;

    vector<string> passwords(p);
    for(int i = 0; i < p; ++i) cin >> passwords[i];

    int n, m;
    char s;

    while(cin >> n >> m >> s) {
        cout << '(' << n << ", " << m << ", " << s << "):";
        for(int i = 0; i < p; ++i) {
            if(valid(passwords[i], n, m, s)) cout << ' ' << passwords[i];
        }
        cout << endl;
    }
}