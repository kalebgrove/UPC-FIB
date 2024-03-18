#include <iostream>
using namespace std;

//Pre: given two numbers, we must simplify the fraction they represent.
//Post: num and den will be changed and therefore the fraction they represent will be irreductible.
int gcd(int n, int m) {
  while(m != 0) {
    int temp = m;
    m = n % m;
    n = temp;
  }
  return n;
}

void read_rational(int& num, int& den) {
  cin >> num;
  char c;
  cin >> c;
  cin >> den;
  int divisor = gcd(num, den);
  num /= divisor;
  den /= divisor;
}

int main() {
  while (true) {
    int num, den;
    read_rational(num, den);
    cout << num << ' ' << den << endl;
  }
}