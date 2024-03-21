#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<char> vec;
    vec.push_back('a');
    vec.push_back('b');
    vec.push_back('c');
    vec.push_back('d');
    vec.push_back('e');
    string next;
    cin >> next;
    for(int i = 0; i < vec.size(); i++) cout << vec[i];
    cout << endl;
    vec.resize(vec.size()-5);
    cin >> next;
    for(int i = 0; i < vec.size(); i++) cout << vec[i];
    cout << endl;
    vec.push_back('d');
    cin >> next;
    for(int i = 0; i < vec.size(); i++) cout << vec[i];
    cout << endl;
    vec.resize(vec.size() - 6);
    cin >> next;
    for(int i = 0; i < vec.size(); i++) cout << vec[i];
    cout << endl;
    vec.resize(vec.size() - 2);
    cin >> next;
    for(int i = 0; i < vec.size(); i++) cout << vec[i];
    cout << endl;
    
}