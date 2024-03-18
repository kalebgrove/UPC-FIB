#include <iostream>

using namespace std;

/*int main() {
    int n;
    cin >> n;
    string star = "";

    for (int n_star = 1; n_star <= n; ++n_star)
    {
        star += '*';
        cout << star << endl;
    }
}*/

/*int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if(j <= i){
            cout << '*';
            }
        }
        cout << endl;
    }    
}*/

int main() {
    int n;
    cin >> n;

    int value = 1;

    for(int i = 0; i < n; ++i) {
        for(int n_star = 0; n_star < value; ++n_star) {
            cout << '*';
            
        }
        cout << endl;
        ++value;
    }
}