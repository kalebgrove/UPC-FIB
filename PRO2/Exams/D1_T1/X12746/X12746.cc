#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
//By declaring a map, we can use the keys as iterators in order to access certain positions.
//By having to iterators, each pointing to each end of the map (if you visualize the map as a vector).
//Modifying the iterators allows us to maintain a vector-like map with each key being a position.

  map<int, int> vec;
  int first = 0;
  int last = -1;

  string command;

//While there is a new command in the input, execute the following code.
  while (cin >> command) {

//Succession of if else statements in order to differentiate the different commands that are sent.
    if (command == "v.push_back(") {
      int value;
      cin >> value;

      string trash;
      cin >> trash;

//If we add an element to the back of the vector, it's like adding a new position to the map. By using these iterators, we create a new space with that new value and insert the desired value from the input.
      
      ++last;
      vec[last] = value;

    } else if (command == "v.push_front(") {
      int value;
      cin >> value;

      string trash;
      cin >> trash;
//If we add a value to the front, the iterator must decrease, since we're following a line that goes from -infinity to +infinity.

        --first;
        vec[first] = value;

    } else if (command == "v.pop_front();") {

//By reducing the size of the "vector", we must add a position to the iterator pointing to the front of the map. In doing so, we make irrelevant the previous position; it will have no effect.

      ++first;

    } else if (command == "v.pop_back();") {

//Same as the previous comment but the opposite.

      --last;

    } else if (command == "v.resize(") {
      int newsize;
      cin >> newsize;

      string trash;
      cin >> trash;


//If the newsize is larger, we must add zeros. This is automatically done by the map if we were to access those positions pointed by the iterator or added.
//If the newsize is smaller, we must remove an interval of values. We use the function .lower_bound() instead of .find(), because the first returns an iterator pointing to a position, the second returns the
//value that is pointed by the iterator.

      if(last-first < newsize) last = first + newsize - 1;
      else if(last-first > newsize) {
        std::map<int, int>::iterator it_bottom = vec.lower_bound(first+newsize);
        vec.erase(it_bottom, vec.end());
        last = first + newsize - 1;
      }

    } else if (command == "cout<<v[") {
      int index;
      cin >> index;

      string trash;
      cin >> trash;

      cout << vec[index+first] << endl;

    } else if (command == "cout<<v;") {

//0 will be printed if the iterator points to a position in the map that has no value stored in it. That's why it's important in resize that we didn't add those zeros manually.
        cout << vec[first];
        for(int iterator = first+1; iterator <= last; ++iterator) {
          cout << ',' << vec[iterator];
        }
        cout << endl;

    } else if (command == "v[") {
      int index;
      cin >> index;
      string mid;
      cin >> mid; // Això consumeix el "]="
      int val;
      cin >> val;
      string trash;
      cin >> trash;

      vec[index+first] = val;

    } else if (command == "//") {
      string comment;
      getline(cin, comment);
      cout << "//" << comment << endl;
    } else {
      cout << "Wrong command '" << command << "'" << endl;
      string discard;
      getline(cin, discard);
    }
  }
}