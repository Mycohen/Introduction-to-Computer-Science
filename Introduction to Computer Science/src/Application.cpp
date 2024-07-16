#include <iostream>

// Include all exercise files
#include "5.1.cpp"
#include "5.2.cpp"
#include "5.3.cpp"
#include "5.4.cpp"
#include "6.1.cpp"
#include "6.2.cpp"
#include "6.3.cpp"
#include "6.4.cpp"
#include "6.5.cpp"
#include "7.1.cpp"
#include "7.2.cpp"
#include "7.3.cpp"
#include "7.4.cpp"
#include "8.1.cpp"
#include "8.2.cpp"
#include "9.cpp"
#include "10.1.cpp"
#include "10.2.cpp"
#include "10.3.cpp"
#include "11.1.cpp"
#include "11.2.cpp"
#include "11.3.cpp"
#include "11.4.cpp"
#include "12.cpp"
#include "13.1.cpp"
#include "13.2.cpp"

void showMainMenu() {
    std::cout << "Welcome to the application of the course 'Introduction to Computer Science'\n";
    std::cout << "Please select a main exercise to run:\n";
    std::cout << "5. Exercise 5\n";
    std::cout << "6. Exercise 6\n";
    std::cout << "7. Exercise 7\n";
    std::cout << "8. Exercise 8\n";
    std::cout << "9. Exercise 9\n";
    std::cout << "10. Exercise 10\n";
    std::cout << "11. Exercise 11\n";
    std::cout << "12. Exercise 12\n";
    std::cout << "13. Exercise 13\n";
    std::cout << "Enter your choice: ";
}

void showSubMenu(int exercise) {
    std::cout << "Please select a sub-exercise to run:\n";
    switch (exercise) {
    case 5:
        std::cout << "1. Exercise 5.1\n";
        std::cout << "2. Exercise 5.2\n";
        std::cout << "3. Exercise 5.3\n";
        std::cout << "4. Exercise 5.4\n";
        break;
    case 6:
        std::cout << "1. Exercise 6.1\n";
        std::cout << "2. Exercise 6.2\n";
        std::cout << "3. Exercise 6.3\n";
        std::cout << "4. Exercise 6.4\n";
        std::cout << "5. Exercise 6.5\n";
        break;
    case 7:
        std::cout << "1. Exercise 7.1\n";
        std::cout << "2. Exercise 7.2\n";
        std::cout << "3. Exercise 7.3\n";
        std::cout << "4. Exercise 7.4\n";
        break;
    case 8:
        std::cout << "1. Exercise 8.1\n";
        std::cout << "2. Exercise 8.2\n";
        break;
    case 9:
        std::cout << "1. Exercise 9.1\n";
        break;
    case 10:
        std::cout << "1. Exercise 10.1\n";
        std::cout << "2. Exercise 10.2\n";
        std::cout << "3. Exercise 10.3\n";
        break;
    case 11:
        std::cout << "1. Exercise 11.1\n";
        std::cout << "2. Exercise 11.2\n";
        std::cout << "3. Exercise 11.3\n";
        std::cout << "4. Exercise 11.4\n";
        break;
    case 12:
        std::cout << "1. Exercise 12.1\n";
        break;
    case 13:
        std::cout << "1. Exercise 13.1\n";
        std::cout << "2. Exercise 13.2\n";
        break;
    default:
        std::cout << "Invalid choice!\n";
        break;
    }
    std::cout << "Enter your choice: ";
}

void runSubExercise(int mainChoice, int subChoice) {
    switch (mainChoice) {
    case 5:
        switch (subChoice) {
        case 1: Exercises::Ex_5_1_main(); break;
        case 2: Exercises::Ex_5_2_main(); break;
        case 3: Exercises::Ex_5_3_main(); break;
        case 4: Exercises::Ex_5_4_main(); break;
        default: std::cout << "Invalid choice!\n"; break;
        }
        break;
    case 6:
        switch (subChoice) {
        case 1: Exercises::Ex_6_1_main(); break;
        case 2: Exercises::Ex_6_2_main(); break;
        case 3: Exercises::Ex_6_3_main(); break;
        case 4: Exercises::Ex_6_4_main(); break;
        case 5: Exercises::Ex_6_5_main(); break;
        default: std::cout << "Invalid choice!\n"; break;
        }
        break;
    case 7:
        switch (subChoice) {
        case 1: Exercises::Ex_7_1_main(); break;
        case 2: Exercises::Ex_7_2_main(); break;
        case 3: Exercises::Ex_7_3_main(); break;
        case 4: Exercises::Ex_7_4_main(); break;
        default: std::cout << "Invalid choice!\n"; break;
        }
        break;
    case 8:
        switch (subChoice) {
        case 1: Exercises::Ex_8_1_main(); break;
        case 2: Exercises::Ex_8_2_main(); break;
        default: std::cout << "Invalid choice!\n"; break;
        }
        break;
    case 9:
        switch (subChoice) {
        case 1: Exercises::Ex_9_main(); break;
        default: std::cout << "Invalid choice!\n"; break;
        }
        break;
    case 10:
        switch (subChoice) {
        case 1: Exercises::Ex_10_1_main(); break;
        case 2: Exercises::Ex_10_2_main(); break;
        case 3: Exercises::Ex_10_3_main(); break;
        default: std::cout << "Invalid choice!\n"; break;
        }
        break;
    case 11:
        switch (subChoice) {
        case 1: Exercises::Ex_11_1_main(); break;
        case 2: Exercises::Ex_11_2_main(); break;
        case 3: Exercises::Ex_11_3_main(); break;
        case 4: Exercises::Ex_11_4_main(); break;
        default: std::cout << "Invalid choice!\n"; break;
        }
        break;
    case 12:
        switch (subChoice) {
        case 1: Exercises::Ex_12_main(); break;
        default: std::cout << "Invalid choice!\n"; break;
        }
        break;
    case 13:
        switch (subChoice) {
        case 1: Exercises::Ex_13_1_main(); break;
        case 2: Exercises::Ex_13_2_main(); break;
        default: std::cout << "Invalid choice!\n"; break;
        }
        break;
    default:
        std::cout << "Invalid choice!\n";
        break;
    }
}

int main() {
    int mainChoice, subChoice;
    showMainMenu();
    std::cin >> mainChoice;
    if (mainChoice >= 5 && mainChoice <= 13) {
        showSubMenu(mainChoice);
        std::cin >> subChoice;
        runSubExercise(mainChoice, subChoice);
    }
    else {
        std::cout << "Invalid choice!\n";
    }
    return 0;
}
