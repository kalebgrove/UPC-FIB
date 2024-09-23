#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool repeat(int m, vector<int> &sequence, int &pos)
{
    int size = sequence.size();

    for (int i = 0; i < size; ++i)
    {
        if (sequence[i] == m)
        {
            pos = i;
            return true;
        }
    }
    return false;
}

int main()
{
    long long int n;
    int x, y;

    while (cin >> x >> y >> n)
    {
        vector<int> sequence;
        unordered_set<int> numbers;
        bool end = false;

        while (not end and n <= 100000000)
        {
            if (numbers.count(n) == 1)
            {
                int pos = -1;
                if (repeat(n, sequence, pos))
                {
                    cout << sequence.size() - pos << endl;
                    end = true;
                }
            }
            sequence.push_back(n);
            numbers.insert(n);

            if (n % 2 == 0)
            {
                n = x + n / 2;
            }
            else
            {
                n = y + 3 * n;
            }
        }

        if (not end)
        {
            cout << n << endl;
        }
    }
}