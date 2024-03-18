/* Comparison of Words - 16/09/2023

    github.com/HoodedHawk21/PersonalProjects
*/

#include <iostream>
#include <string> //Declaring a string to be able to use the variable "string"

using namespace std;

/*int main() {
    string word1, word2; 
    cin >> word1 >> word2;
    string f_word, l_word; // first versus last word

    if(word1 < word2) f_word = word1, l_word = word2;
    if(word1 > word2) f_word = word2, l_word = word1;
    if (word1 == word2)
    {
        cout << word1 << " = " << word2 << endl;
    }

    cout << f_word << " < " << l_word << endl;    

}*/

int main(){
    string word1, word2;
    cin >> word1 >> word2;
    string value; //String that contains the direction of the greater than symbol.

    if(word1 < word2) value = " < ";
    if(word2 < word1) value = " > ";
    if(word1 == word2) value = " = ";

    cout << word1 << value << word2 << endl;
}