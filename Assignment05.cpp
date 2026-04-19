#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ofstream output("original.txt");

    if (!output) {
        cerr << "Error: Could not create the original file." << endl;
        return 1;
    }

    output << "One" << endl;
    output << "Two" << endl;
    output << "Three" << endl;
    output << "Four" << endl;
    output << "Five" << endl;
    output << "Six" << endl;

    output.close();

    ifstream input("original.txt");
    vector<string> words;
    string word;

    if (!input) {
        cerr << "Error: Could not open the file for reading." << endl;
        return 1;
    }

    while (input >> word) {
        words.push_back(word);
    }
    input.close();

    sort(words.begin(), words.end());

    ofstream sortedOutput("sorted.txt");

    if (!sortedOutput) {
        cerr << "Error: Could not create the sorted file." << endl;
        return 1;
    }

    for (const string& s : words) {
        sortedOutput << s << endl;
    }

    sortedOutput.close();

    cout << "All set! 'original.txt' was created and 'sorted.txt' is now organized alphabetically." << endl;

    return 0;
}
