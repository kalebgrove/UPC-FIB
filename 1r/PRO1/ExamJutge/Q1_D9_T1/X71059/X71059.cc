#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Programmers{
    string name, origin;
    int exp;
};

void read_programmers(vector<Programmers>& names, int n, string origin) {
    for(int i = 0; i < n; ++i) {
        cin >> names[i].name >> names[i].exp;
        names[i].origin = origin;
    }
}

bool comp(Programmers a, Programmers b) {
    if(a.exp != b.exp) return a.exp > b.exp;
    return a.name < b.name;
}

bool comp2(Programmers a, Programmers b) {
    return a.name < b.name;
}

void fuse(vector<Programmers>& list, vector<Programmers>& list1, vector<Programmers>& list2, int n) {
    int i = 0, j = 0, k = 0;
    int p_counter = 0, i_counter = 0;
    while(k < list.size()) {
        if(k%n == 0) {
            i_counter = 0;
            p_counter = 0;
        }
        // First case scenario the experience level is different.
        if(list1[i].exp > list2[j].exp) {
            list[k] = list1[i];
            ++i;
            ++i_counter;
        } else if(list1[i].exp < list2[j].exp) {
            list[k] = list2[j];
            ++j;
            ++p_counter;
        //Now what happens if the experience level is the same?
        } else {
            //Second case scenario the amount of palestineans.
            if(p_counter > i_counter and n > 1) {
                list[k] = list1[i];
                ++i;
                ++i_counter;
            //Third case scenario there are more israelis.
            } else if (i_counter > p_counter and n > 1) {
                list[k] = list2[j];
                ++j;
                ++p_counter;
            //Fourth case scenario the amount is the same, so we take the person whos name is first in lexicografic order.
            //We also take into consideration the fact that the groups are larger than one person (exclusive).
            } else {
                if(list1[i].name < list2[j].name) {
                    list[k] = list1[i];
                    ++i;
                    ++i_counter;
                } else {
                    list[k] = list2[j];
                    ++j;
                    ++p_counter;
                }
            }
        }
        ++k;
        //Once the index has reached the vector size, that means that we no longer need to fuse both vectors, just concatenate.
        if(i == list1.size()) {
            while(j < list2.size() and k < list.size()) {
                list[k] = list2[j];
                ++j;
                ++k;
            }
        } else if(j == list2.size()) {
            while(i < list1.size() and k < list.size()) {
                list[k] = list1[i];
                ++i;
                ++k;
            }
        }
    }
}

vector<Programmers> aux(vector<Programmers>& list, int n, int i) {
    vector<Programmers> aux(n);

    int j = i, k = 0;
    while(k < n and j < n+i) {
        aux[k] = list[j];
        ++k;
        ++j;
    }

    sort(aux.begin(), aux.end(), comp2);
    return aux;
}

void print(vector<Programmers> w) {
    cout << w[0].name;
    for(int j = 1; j < w.size(); ++j) cout << ' ' << w[j].name;
    cout << endl;
}

int main() {
    int k;
    while(cin >> k) {
        int n1;
        cin >> n1;
        vector<Programmers> list1(n1);

        read_programmers(list1, n1, "israel");

        int n2;
        cin >> n2;
        vector<Programmers> list2(n2);

        read_programmers(list2, n2, "palestine");

        vector<Programmers> list(n1+n2);

        fuse(list, list1, list2, k);

        vector<Programmers> w(k);

        int i = 0;
        while(i < n1+n2) {
            w = aux(list, k, i);
            print(w);
            i += k;
        }

        cout << endl;
    }
}