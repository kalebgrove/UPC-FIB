#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int num = 0;
    string s;

    while(cin >> n and n != 0) {
        int temp_count = 0;
        int ctr = 0;
        ++num;

        for(int i = 0; i < n; ++i) {
            cin >> s;
            int j = 1;
            bool end = false;

            if(s[0] == 'r' and s[1] == 'r') {
                    ++temp_count;
                    end = true;
            }

            while(j < s.size()-1 and not end) {
                if(s[j] == 'r' and s[j+1] == 'r' and s[j-1] != 'a' and s[j-1] != 'e' and s[j-1] != 'i' and s[j-1] != 'o' and s[j-1] != 'u') {
                    ++temp_count;
                    end = true;
                }
                ++j;
            }
            if(not end) temp_count = 0;
            if(temp_count == 2) {
                ++ctr;
                temp_count = 1;
            }
            //cout << s << ' ' << ctr << ' ' << temp_count << endl;
        }
        cout << num << ": " << ctr << endl;
    }
}