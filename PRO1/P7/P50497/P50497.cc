#include <iostream>
#include <vector>

using namespace std;

bool is_palindrome(const string& s) {
    int start = 0;
    int end = s.size() - 1;
    while(start < end) {
        if(s[start] != s[end]) return false;
        ++start;
        --end;
    }
    return true;
}