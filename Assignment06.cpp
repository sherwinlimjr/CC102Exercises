#include <iostream>
#include <fstream>

using namespace std;

//write NUM.TXT first
//sherwinlim
bool isPrime(int n) {
    if (n < 2) return false;

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream inputFile("NUMS.TXT");
    int number;
    int count = 0;


    if (!inputFile) {
        cout << "File not found!" << endl;
        return 1;
    }


    while (inputFile >> number) {
        if (isPrime(number)) {
            count++;
        }
    }

    cout << "Total prime numbers: " << count << endl;

    inputFile.close();
    return 0;
}
