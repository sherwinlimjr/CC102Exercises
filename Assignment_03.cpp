#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

//struct
struct Book {
    string barcode;
    string title;
    int year;
    int rating;
};

//category
string getCategory(int rating) {
    if (rating == 5) return "Excellent";
    else if (rating == 4) return "Very Good";
    else if (rating == 3) return "Good";
    else if (rating == 2) return "Fair";
    else if (rating == 1) return "Poor";
    else return "No Rating";
}

// Function prototypes
void inputBooks(Book books[], int size);
void displayBooks(const Book books[], int size);


bool isDuplicate(Book books[], int size, string code) {
    for (int i = 0; i < size; i++) {
        if (books[i].barcode == code) {
            return true;
        }
    }
    return false;
}
//input 
void inputBooks(Book books[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "\nBook " << i + 1 << "\n";

        while (true) {
            cout << "Enter Barcode: ";
            cin >> books[i].barcode;

            if (isDuplicate(books, i, books[i].barcode)) {
                cout << "Duplicate barcode! Enter again.\n";
            } else {
                break;
            }
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Title: ";
        getline(cin, books[i].title);

        cout << "Enter Year Published: ";
        cin >> books[i].year;

        while (true) {
            cout << "Enter Rating (0-5): ";
            cin >> books[i].rating;

            if (books[i].rating >= 0 && books[i].rating <= 5) {
                break;
            } else {
                cout << "Invalid rating! Try again.\n";
            }
        }
    }
}
//display
void displayBooks(const Book books[], int size) {
    cout << "\n\n===== BOOK LIST =====\n";
    cout << left << setw(15) << "Barcode"
         << setw(30) << "Title"
         << setw(10) << "Year"
         << setw(8) << "Rating"
         << "Category" << endl;
    cout << string(73, '-') << endl;

    for (int i = 0; i < size; i++) {
        cout << left << setw(15) << books[i].barcode
             << setw(30) << books[i].title
             << setw(10) << books[i].year
             << setw(8) << books[i].rating
             << getCategory(books[i].rating) << endl;
    }
}

//main
int main() {
    char choice;
    //loop 
    do {
        int n;
        cout << "Enter number of books: ";
        cin >> n;

        Book* books = new Book[n];

        inputBooks(books, n);
        displayBooks(books, n);

        delete[] books;

        cout << "\nRun again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}