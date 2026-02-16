#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char repeat;

    do {
        double sales[5][4] = {0};
        int salesperson, product;
        double amount;

        while (true) {
            cout << "Enter salesperson number (1-4) or 0 to stop: ";
            cin >> salesperson;
            if (salesperson == 0) break;

            cout << "Enter product number (1-5): ";
            cin >> product;

            cout << "Enter amount sold: ";
            cin >> amount;

            sales[product - 1][salesperson - 1] += amount;
        }

        cout << "\n\tSalesperson\nProduct\t1\t2\t3\t4\tTotal\n";

        double grandTotal = 0;

        for (int i = 0; i < 5; i++) {
            double rowTotal = 0;
            cout << i + 1 << "\t";

            for (int j = 0; j < 4; j++) {
                cout << fixed << setprecision(2) << sales[i][j] << "\t";
                rowTotal += sales[i][j];
            }

            cout << rowTotal << endl;
            grandTotal += rowTotal;
        }

        cout << "Total\t";
        for (int j = 0; j < 4; j++) {
            double colTotal = 0;
            for (int i = 0; i < 5; i++) {
                colTotal += sales[i][j];
            }
            cout << fixed << setprecision(2) << colTotal << "\t";
        }

        cout << grandTotal << endl;

        cout << "\nRun again? (y/n): ";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}