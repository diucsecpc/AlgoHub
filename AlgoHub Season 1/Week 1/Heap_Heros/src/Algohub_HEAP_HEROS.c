#include <stdio.h>

#define MAX_GRADES 10
#define MIN_GRADES 5

void get_grades(float grades[], int *num_grades) {
    int i;
    printf("Enter the number of grades (between %d and %d): ", MIN_GRADES, MAX_GRADES);
    scanf("%d", num_grades);

    while (*num_grades < MIN_GRADES || *num_grades > MAX_GRADES) {
        printf("Invalid number of grades. Please enter a number between %d and %d: ", MIN_GRADES, MAX_GRADES);
        scanf("%d", num_grades);
    }

    for (i = 0; i < *num_grades; i++) {
        printf("Enter grade %d: ", i + 1);
        scanf("%f", &grades[i]);
        while (grades[i] < 0) {
            printf("Invalid grade. Please enter a non-negative grade: ");
            scanf("%f", &grades[i]);
        }
    }
}

void calculate_statistics(float grades[], int num_grades, float *average, float *highest, float *lowest) {
    int i;
    float sum = 0;
    *highest = grades[0];
    *lowest = grades[0];

    for (i = 0; i < num_grades; i++) {
        sum += grades[i];
        if (grades[i] > *highest) {
            *highest = grades[i];
        }
        if (grades[i] < *lowest) {
            *lowest = grades[i];
        }
    }

    *average = sum / num_grades;
}

void update_grades(float grades[], int num_grades) {
    int index;
    float new_grade;

    printf("Enter the index of the grade to update (0 to %d): ", num_grades - 1);
    scanf("%d", &index);

    while (index < 0 || index >= num_grades) {
        printf("Invalid index. Please enter a number between 0 and %d: ", num_grades - 1);
        scanf("%d", &index);
    }

    printf("Enter the new grade: ");
    scanf("%f", &new_grade);

    while (new_grade < 0) {
        printf("Invalid grade. Please enter a non-negative grade: ");
        scanf("%f", &new_grade);
    }

    grades[index] = new_grade;
}

int main() {
    float grades[MAX_GRADES];
    int num_grades;
    float average, highest, lowest;
    char choice;

    get_grades(grades, &num_grades);
    calculate_statistics(grades, num_grades, &average, &highest, &lowest);

    printf("Average grade: %.2f\n", average);
    printf("Highest grade: %.2f\n", highest);
    printf("Lowest grade: %.2f\n", lowest);

    do {
        printf("Do you want to update any grades? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            update_grades(grades, num_grades);
            calculate_statistics(grades, num_grades, &average, &highest, &lowest);

            printf("Updated average grade: %.2f\n", average);
            printf("Updated highest grade: %.2f\n", highest);
            printf("Updated lowest grade: %.2f\n", lowest);
        }
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
