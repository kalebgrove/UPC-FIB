#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;

int common_elements(const VI& X, const VI& Y) {
    int count = 0, i = 0, j = 0;
    while(i < X.size() and j < Y.size()) {
        if(X[i] > Y[j]) ++j;
        else if(X[i] < Y[j]) ++i;
        else {
            ++count;
            ++i;
            ++j;
        }
    }
    return count;
}