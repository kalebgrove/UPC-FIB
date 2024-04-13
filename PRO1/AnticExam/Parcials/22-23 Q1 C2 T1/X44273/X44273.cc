#include <iostream>
#include <vector>

using namespace std;

int num_key(const vector<int>& files, int x) {
    int sum = 0;
    for(int i = 0; i < files.size(); ++i) {
        for(int j = 0; j < files.size(); ++j) {
            if(i != j) sum = files[i]+files[j];
            if(sum == x) return min(i, j);
        }
    }
    return -1;
}

int main() {
    int n; //Number of files on my computer;
    cin >> n;

    vector<int> files(n);
    for(int i = 0; i < n; ++i) {
        cin >> files[i];
    }

    int m; //Numbers that can be the key.

    while(cin >> m) {
        int number = num_key(files, m);
        if(number != -1) cout << number << endl;
    }
    
}