#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_set>
#include <iterator>

using namespace std;

int uniqueMorseTransformations(const vector<string>& words)
{
    vector<string> morseMap =
    {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
        "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
        "..-", "...-", ".--", "-..-", "-.--", "--.."
    };

    unordered_set<string> uniqueTransformations;

    for (const auto& word : words)
    {
        string morseTransformation;
        for (char c : word)
        {
            morseTransformation += morseMap[c - 'a'];
        }
        uniqueTransformations.insert(morseTransformation);
    }


    for (const auto& transformation : uniqueTransformations)
    {
        cout << transformation << " "<<endl;
    }

    return uniqueTransformations.size();
}


int main()
{
    vector<string> words;
    int option;
    cin >> option;

    words.resize(option);


    for(int i = 0; i < option; i++)
    {
        cin >> words[i];
    }

    int numTransformations = uniqueMorseTransformations(words);
    cout<< numTransformations << endl;


    return 0;
}
