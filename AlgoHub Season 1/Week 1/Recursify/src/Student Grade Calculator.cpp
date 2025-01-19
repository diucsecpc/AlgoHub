#include <iostream>
using namespace std;

// Function to calculate and display average, highest, and lowest grades
void calculateStatistics(float grades[], int count) {
    if (count == 0) {
        cout << "No grades available.\n";
        return;
    }
    float sum = 0, highest = grades[0], lowest = grades[0];
    for (int i = 0; i < count; i++) {
        sum += grades[i];
        if (grades[i] > highest) highest = grades[i];
        if (grades[i] < lowest) lowest = grades[i];
    }
    float average = sum / count;
    cout << "Average grade: " << average << endl;
    cout << "Highest grade: " << highest << endl;
    cout << "Lowest grade: " << lowest << endl;
}

// Function to update a grade
void updateGrade(float grades[], int count) {
    int index;
    float newGrade;
    cout << "Enter the index (1-" << count << ") of the grade to update: ";
    cin >> index;
    if (index < 1 || index > count) {
        cout << "Invalid index.\n";
        return;
    }
    cout << "Enter the new grade (0.0-4.0): ";
    cin >> newGrade;
    if (newGrade < 0.0 || newGrade > 4.0) {
        cout << "Invalid grade value.\n";
        return;
    }
    grades[index - 1] = newGrade;
    cout << "Grade updated successfully.\n";
}

// Function to display all grades
void displayGrades(float grades[], int count) {
    if (count == 0) {
        cout << "No grades available.\n";
        return;
    }
    cout << "All grades:\n";
    for (int i = 0; i < count; i++) {
        cout << "Student " << (i + 1) << ": " << grades[i] << endl;
    }
}

int main() {
    float grades[100];
    int numGrades;

    cout << "Enter the number of students: ";
    cin >> numGrades;
    if (numGrades <= 0 || numGrades > 100) {
        cout << "Invalid number of students. Program exiting.\n";
        return 1;
    }

    cout << "Enter the grades (0.0-4.0):\n";
    for (int i = 0; i < numGrades; i++) {
        cout << "Enter student " << (i + 1) << " grade: ";
        cin >> grades[i];
        if (grades[i] < 0.0 || grades[i] > 4.0) {
            cout << "Invalid grade. Please enter a value between 0.0 and 4.0.\n";
            i--; // Retry the current index
        }
    }

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. View statistics\n";
        cout << "2. Update a grade\n";
        cout << "3. Show all grades\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            calculateStatistics(grades, numGrades);
        } else if (choice == 2) {
            updateGrade(grades, numGrades);
        } else if (choice == 3) {
            displayGrades(grades, numGrades);
        } else if (choice == 4) {
            cout << "Exiting program.\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
