 #include <iostream>

 using namespace std;

 int main() {
    string word;
    bool found = false;
    int count = -1;

    while(word != "beginning" and cin >> word){
    }
    while(not found and cin >> word) {
        if(word == "end") found = true;
        ++count;
    }
    if(not found) cout << "wrong sequence" << endl;
    else cout << count << endl;
 }