#include <iostream>
#include <vector>

using namespace std;

vector<int> concatenation(const vector<int>& v1, const vector<int>& v2) {
    vector<int> w(v1.size()+v2.size());
    for(int i = 0; i < v1.size(); ++i) w[i] = v1[i];
    int j = v1.size();
    for(int i = 0; i < v2.size(); ++i) {
        w[j] = v2[i];
        ++j;
    }
    return w;
}

int main() {
    vector<int> v1{1, 2, 3};
    vector<int> v2{4, 5, 6};
    vector<int> w = concatenation(v1, v2);
    for(int i = 0; i < w.size(); ++i) cout << w[i];
    cout << endl;
}