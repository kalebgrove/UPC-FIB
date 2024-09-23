#include <iostream>
#include <vector>

using namespace std;

/*int evaluate(const vector<int>& p, int x) {
    int sum = 0;
    for(int i = 0; i < p.size() - 1; ++i) {
        sum = sum + p[i] * pow(x, i);
    }
    return sum;
}*/

int evaluate(const vector<int>& p, int x) {
    int sum = p[p.size() - 1];
    for(int i = p.size() - 2; i >= 0; --i) sum = sum*x + p[i];
    return sum;
}