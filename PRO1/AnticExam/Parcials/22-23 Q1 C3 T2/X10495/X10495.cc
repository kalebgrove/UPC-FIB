#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int var;
    int count = 0;

    for(int i = 0; i < m; ++i) {
        cin >> var;
        int max_2 = var, min_2 = var;
        for(int j = 1; j < n; ++j) {
            cin >> var;
            if(var <= max_2 and var > min_2) max_2 = var;
        }
    }
}