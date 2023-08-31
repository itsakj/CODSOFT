#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> studentNames;
    vector<double> studentGrades;

    int numStudents;

    cout << "Enter the number of students: ";
    cin >> numStudents;

    for (int i = 0; i < numStudents; ++i) {
        string name;
        double grade;

        cout << "Enter name of student " << i + 1 << ": ";
        cin.ignore(); // Clear the newline character from previous input
        getline(cin, name);

        cout << "Enter grade of student " << i + 1 << ": ";
        cin >> grade;

        studentNames.push_back(name);
        studentGrades.push_back(grade);
    }

    double sumGrades = 0.0;
    double highestGrade = studentGrades[0];
    double lowestGrade = studentGrades[0];

    for (double grade : studentGrades) {
        sumGrades += grade;
        highestGrade = max(highestGrade, grade);
        lowestGrade = min(lowestGrade, grade);
    }

    double averageGrade = sumGrades / numStudents;

    cout << "\nStudent Grades Summary:\n";
    cout << "Average Grade: " << averageGrade << endl;
    cout << "Highest Grade: " << highestGrade << endl;
    cout << "Lowest Grade: " << lowestGrade << endl;

    return 0;
}