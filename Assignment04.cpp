#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream writer("color.txt");

    if (!writer) {
        cerr << "Something went wrong creating the file." << endl;
        return 1;
    }

    writer << "Blue" << endl;
    writer << "Orange" << endl;
    writer << "Green" << endl;
    writer << "Slate Gray" << endl;
    writer << "Lavender" << endl;

    writer.close();

    ifstream reader("color.txt");
    ofstream copier("color_copy.txt");

    if (!reader || !copier) {
        cerr << "The program couldn't access the files to copy them." << endl;
        return 1;
    }

    string line;
    while (getline(reader, line)) {
        copier << line << endl;
    }

    reader.close();
    copier.close();

    cout << "Process complete! Your files are ready." << endl;

    return 0;
}
