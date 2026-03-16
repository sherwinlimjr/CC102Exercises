#include <iostream>
using namespace std;

int process(int *grades, int students, int subjects);

int main()
{

    int stu,sub;

    cout << "\n Enter the number of students: ";
    cin >> stu;

    cout << "\n Enter the number of subjects: ";
    cin >> sub;

    int grades[stu][sub];

    cout << "\n Enter the grades for each student:"<<endl;
    for(int i = 0; i < stu; i++) {
        for(int j = 0; j < sub; j++) {

            cout << "Student (" << i+1 << ") Subject " << j+1 << ": ";
            cin >> grades[i][j];
        }
    }
    process(&grades[0][0], stu, sub);
}



int process(int *grades, int students, int subjects)
{

    cout<<"\n grade in the matrix:"<<endl;;

    for(int i = 0; i < students; i++) {
        for(int j = 0; j < subjects; j++) {
            cout << *(grades + i * subjects + j) << "\t";
        }
        cout<<endl;
    }

    cout << "average grade of each student:"<<endl;;


    for(int i = 0; i < students; i++) {

        int total = 0;

        for(int j = 0; j < subjects; j++) {
            total += *(grades + i * subjects + j);
        }
        double avrge = (double)total / subjects;
        cout<<"Student (" << i + 1 << ") average: "<<avrge<< endl;
    }


    int high = *grades;

    for(int i = 0; i < students; i++) {
        for(int j = 0; j < subjects; j++) {

            int intgrade = *(grades + i * subjects + j);

            if(intgrade > high) {
                high = intgrade;
            }
        }
    }

    cout << "\n Highest grade in the matrix: " << high << endl;

    return high;
}
