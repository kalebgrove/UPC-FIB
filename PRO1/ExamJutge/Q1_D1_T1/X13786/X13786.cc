#include <iostream>
#include <string>

using namespace std;

int main() {
    string name;
    string trash;
    int age;
    while (cin >> trash >> trash >> trash >> name >> trash >> trash >> trash >> age >> trash >> trash) { // We clean out the useless strings with string trash.

    cout << name << ", you look younger. I thought you were " << age-age/10 << " years old." << endl;
    }
}