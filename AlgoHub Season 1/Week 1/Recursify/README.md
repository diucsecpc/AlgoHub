
# Student Grade Calculator  
**Week :** 01  
**Team Name :** Recursify  

---

## Features Implemented

1. **Dynamic Grade Input**:
   - Accepts grades for any number of students.
   - Grades are floating-point values between `0.0` and `4.0`.

2. **Statistics Calculation**:
   - Computes the average, highest, and lowest grades.

3. **Update Grades**:
   - Allows modification of any grade by specifying the student index.

4. **Grade Display**:
   - Displays all entered grades with corresponding student numbers.

5. **Input Validation**:
   - Ensures grades are valid before processing.

6. **Menu Navigation**:
   - User-friendly menu for interacting with the program.

---

## How to Run the Program

1. **Compile the Program**:
   - Use any C++ compiler to compile the program.
   - Example:
     ```
     g++ -o grade_calculator grade_calculator.cpp
     ```

2. **Run the Program**:
   - Execute the compiled program.
     ```
     ./grade_calculator
     ```

3. **Follow the Instructions**:
   - Input the number of students and their grades.
   - Use the menu to view statistics, update grades, or display all grades.

---

## Sample Input/Output

### Sample Input:
```
Enter the number of students: 3
Enter student 1 grade: 3.5
Enter student 2 grade: 4.0
Enter student 3 grade: 2.8
```

### Menu:
```
Menu:
1. View statistics
2. Update a grade
3. Show all grades
4. Exit
Choose an option: 1
```

### Sample Output:
```
Average grade: 3.43333
Highest grade: 4.0
Lowest grade: 2.8
```

---

## Concepts Used from Week's Topics

1. **Complexity**:
   - Analysis of time and space complexity for each function.

2. **Big O**:
   - Identification of worst-case scenarios during operations.

3. **Time Complexity**:
   - Grade traversal for statistics: O(n).
   - Update operation: O(1).

4. **Space Complexity**:
   - Fixed memory allocation for grades array: O(n).

5. **Asymptotic Analysis**:
   - Consideration of the program's behavior for large input sizes.

6. **Array Operations**:
   - **Traversal**: Looping through grades to calculate statistics.
   - **Insertion**: Adding grades dynamically to the array.
   - **Deletion**: Not explicitly implemented but logically managed by updates.
   - **Application**: Efficiently storing and processing student grades.

---

## Author

Mir Yeasir Abrar <br/>
**Team Name:** Recursify  
 
