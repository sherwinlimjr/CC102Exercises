#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    char repeat;

    do {
        int students, quizzes;
        cout << "Enter number of students: ";
        cin >> students;
        cout << "Enter number of quizzes: ";
        cin >> quizzes;

        double scores[50][50];
        double avg[50];

        for (int i = 0; i < students; i++) {
            double sum = 0;
            cout << "Enter scores for Student " << i + 1 << ":\n";
            for (int j = 0; j < quizzes; j++) {
                cin >> scores[i][j];
                sum += scores[i][j];
            }
            avg[i] = sum / quizzes;
        }

        cout << "\nStudent\t";
        for (int j = 0; j < quizzes; j++) {
            cout << "Q" << j + 1 << "\t";
        }
        cout << "Average\n";

        for (int i = 0; i < students; i++) {
            cout << i + 1 << "\t";
            for (int j = 0; j < quizzes; j++) {
                cout << scores[i][j] << "\t";
            }
            cout << fixed << setprecision(2) << avg[i] << endl;
        }

        cout << "\nRun again? (y/n): ";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}