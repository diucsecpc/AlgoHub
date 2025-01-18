#include <iostream>
#include <limits>

using namespace std;

/**
 * Input grades of n students.
 * @param grades array of grades
 * @param n number of students
 */
void inputGrades(int grades[], int n) {
    int grade;
    for (int i = 0; i < n; ++i) {
        while (true) {
            cout << "Enter grade for student " << i + 1 << ": ";
            cin >> grade;
            if (cin.fail() || grade < 0) {
                cin.clear(); // clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
                cout << "Invalid input. Please enter a non-negative integer." << endl;
            } else {
                grades[i] = grade;
                break;
            }
        }
    }
}

/**
 * Update a grade of a student.
 * @param grades array of grades
 * @param n number of students
 */
void updateGrade(int grades[], int n) {
    int index, newGrade;
    while (true) {
        cout << "Enter the student number to update (1-" << n << "): ";
        cin >> index;
        if (cin.fail() || index < 1 || index > n) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid student number." << endl;
        } else {
            break;
        }
    }
    while (true) {
        cout << "Enter the new grade for student " << index << ": ";
        cin >> newGrade;
        if (cin.fail() || newGrade < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a non-negative integer." << endl;
        } else {
            grades[index - 1] = newGrade;
            break;
        }
    }
}

/**
 * Calculate the average of the grades.
 * @param grades array of grades
 * @param n number of students
 * @return average of the grades
 */
double calculateAverage(const int grades[], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += grades[i];
    }
    return static_cast<double>(sum) / n;
}

/**
 * Find the highest grade.
 * @param grades array of grades
 * @param n number of students
 * @return highest grade
 */
int findHighest(const int grades[], int n) {
    int highest = grades[0];
    for (int i = 1; i < n; ++i) {
        if (grades[i] > highest) {
            highest = grades[i];
        }
    }
    return highest;
}

/**
 * Find the lowest grade.
 * @param grades array of grades
 * @param n number of students
 * @return lowest grade
 */
int findLowest(const int grades[], int n) {
    int lowest = grades[0];
    for (int i = 1; i < n; ++i) {
        if (grades[i] < lowest) {
            lowest = grades[i];
        }
    }
    return lowest;
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    int grades[n];  // array to store grades of n students
    inputGrades(grades, n);

    cout << "Average grade: " << calculateAverage(grades, n) << endl;
    cout << "Highest grade: " << findHighest(grades, n) << endl;
    cout << "Lowest grade: " << findLowest(grades, n) << endl;

    char choice;
    cout << "a. List of grades" << endl;
    cout << "b. Update a grade" << endl;
    cout << "q. Quit" << endl;

    cin >> choice;

    switch(choice) {
        case 'a':
            cout << "Grades:" << endl;
            for (int i = 0; i < n; ++i) {
                cout << "Student " << i + 1 << ": " << grades[i] << endl;
            }
            break;
        case 'b':
            updateGrade(grades, n);
            cout << "Updated grades:" << endl;
            for (int i = 0; i < n; ++i) {
                cout << "Student " << i + 1 << ": " << grades[i] << endl;
            }
            cout << "Average grade: " << calculateAverage(grades, n) << endl;
            cout << "Highest grade: " << findHighest(grades, n) << endl;
            cout << "Lowest grade: " << findLowest(grades, n) << endl;
            break;
        case 'q':
            break;
        default:
            cout << "Invalid choice." << endl;
    }

    return 0;
}
