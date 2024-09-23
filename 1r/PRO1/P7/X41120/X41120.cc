#include <iostream>
#include <vector>

using namespace std;

vector<int> calcula_cims(const vector<int>& v) {
    vector<int> cims;
    for(int i = 1; i < v.size() - 1; ++i) {
        if(v[i] > v[i-1] and v[i] > v[i+1]) cims.push_back(v[i]);
    }
    return cims;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];

    vector<int> cims = calcula_cims(v);
    cout << cims.size() << ":";
    for(int i = 0; i < cims.size(); ++i) cout << ' ' << cims[i];
    cout << endl;
    bool first = true;
    for(int i = 0; i < cims.size(); ++i) {
        if(cims[i] > cims[cims.size()-1]) {
            if(not first) cout << ' ';
            cout << cims[i];
            first = false;
        }
    }
    if(first) cout << '-';
    cout << endl;
}