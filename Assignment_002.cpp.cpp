#include <iostream>
using namespace std;

int analyze(int *grades, int students, int subjects) {

    cout << "\ngrade in the matrix:\n";


    for(int i = 0; i < students; i++) {
        for(int j = 0; j < subjects; j++) {
            cout << *(grades + i * subjects + j) << "\t";
        }
        cout << endl;
    }

    cout << "\nAverage grade of each student:\n";


    for(int i = 0; i < students; i++) {

        int total = 0;

        for(int j = 0; j < subjects; j++) {
            total += *(grades + i * subjects + j);
        }

        double average = (double)total / subjects;

        cout << "Student " << i + 1 << " average: " << average << endl;
    }


    int highest = *grades;

    for(int i = 0; i < students; i++) {
        for(int j = 0; j < subjects; j++) {

            int currentGrade = *(grades + i * subjects + j);

            if(currentGrade > highest) {
                highest = currentGrade;
            }
        }
    }

    cout << "\nHighest grade in the matrix: " << highest << endl;

    return highest;
}

int main() {

    int students, subjects;

    cout << "Enter the number of students: ";
    cin >> students;

    cout << "Enter the number of subjects: ";
    cin >> subjects;

    int grades[students][subjects];1

    cout << "\nEnter the grades for each student:\n";
    for(int i = 0; i < students; i++) {
        for(int j = 0; j < subjects; j++) {

            cout << "Student " << i + 1 << ", Subject " << j + 1 << ": ";
            cin >> grades[i][j];
        }
    }
    analyze(&grades[0][0], students, subjects);

    return 0;
}
