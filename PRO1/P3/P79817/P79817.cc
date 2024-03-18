#include <iostream>

using namespace std;

int main(){
    int a, b;

while(cin >> a >> b){
    int result = a;
    for (int i = 1; i < b; ++i)
    {
        result *= a;
    }

    if (b == 0)
    {
        result = 1;
    }
    cout << result << endl;
}
}