#include <iostream>
using namespace std;

const int MAX_COURSES = 5;
string courses[MAX_COURSES] = {"C++ Basics", "Python", "Web Development", "Machine Learning", "Graphic Designing"};
int role = 0;
int studentProgress = 0;

const int TOTAL_QUESTIONS = 5;
string questions[TOTAL_QUESTIONS] = {
    "What does CPU stand for? (1) Central Processing Unit (2) Computer Power Unit",
    "Which device is used to input text? (1) Monitor (2) Keyboard",
    "Which one is an output device? (1) Printer (2) Mouse",
    "Which language is used for web development? (1) C++ (2) HTML",
    "What is used to store data permanently? (1) Hard Drive (2) RAM"
};
int correctAnswers[TOTAL_QUESTIONS] = {1, 2, 1, 2, 1};

void login() {
    cout << "\n============================\n";
    cout << "  Welcome to the E-Learning System\n";
    cout << "============================\n";
    cout << "Please login by selecting your role:\n";
    cout << "1. Admin\n";
    cout << "2. Instructor\n";
    cout << "3. Student\n";
    cout << "4. Exit\n";  // Added exit option
    cout << "Enter your choice (1, 2, 3, 4): ";
    cin >> role;

    if (role < 1 || role > 4) {
        cout << "Invalid choice, please try again.\n";
        login();
    }
}

void viewCourses() {
    cout << "\nAvailable Courses:\n";
    for (int i = 0; i < MAX_COURSES; i++) {
        cout << i + 1 << ". " << courses[i] << endl;
    }
}

void takeQuiz() {
    if (role != 3) {
        cout << "Only students can take the quiz!\n";
        return;
    }

    int score = 0, ans;
    cout << "\nQuiz Start!\n";
    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        cout << "Q" << i + 1 << ": " << questions[i] << endl;
        cout << "Enter your answer (1 or 2): ";
        cin >> ans;
        if (ans == correctAnswers[i]) {
            score++;
        }
    }
    cout << "Your Score: " << score << "/" << TOTAL_QUESTIONS << endl;
    studentProgress = score * 50;
}

void viewProgress() {
    if (role == 3) {
        cout << "\nYour Progress: " << studentProgress << "% Complete\n";
    }
}

void generateCertificate() {
    if (role == 3 && studentProgress == 100) {
        cout << "?? Congratulations! Certificate Generated ??\n";
    } else {
        cout << "Certificate will be available when progress reaches 100%!\n";
    }
}

void adminMenu() {
    while (true) {
        int choice;
        cout << "\n===== Admin Menu =====\n";
        cout << "1. View Courses\n";
        cout << "2. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            viewCourses();
        } else if (choice == 2) {
            cout << "Logging out...\n";
            break;
        } else {
            cout << "Invalid choice, try again.\n";
        }
    }
}

void instructorMenu() {
    while (true) {
        int choice;
        cout << "\n===== Instructor Menu =====\n";
        cout << "1. View Courses\n";
        cout << "2. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            viewCourses();
        } else if (choice == 2) {
            cout << "Logging out...\n";
            break;
        } else {
            cout << "Invalid choice, try again.\n";
        }
    }
}

void studentMenu() {
    while (true) {
        int choice;
        cout << "\n===== Student Menu =====\n";
        cout << "1. View Courses\n";
        cout << "2. Take Quiz\n";
        cout << "3. View Progress\n";
        cout << "4. Generate Certificate\n";
        cout << "5. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            viewCourses();
        } else if (choice == 2) {
            takeQuiz();
        } else if (choice == 3) {
            viewProgress();
        } else if (choice == 4) {
            generateCertificate();
        } else if (choice == 5) {
            cout << "Logging out...\n";
            break;
        } else {
            cout << "Invalid choice, try again.\n";
        }
    }
}

void menu() {
    if (role == 1) {
        adminMenu();
        cout << "\nAdmin logged out.\n";
    } else if (role == 2) {
        instructorMenu();
        cout << "\nInstructor logged out.\n";
    } else if (role == 3) {
        studentMenu();
        cout << "\nStudent logged out.\n";
    } else if (role == 4) {
        cout << "Exiting the program...\n";
        exit(0);  // Exit the program if user selects option 4
    }
}

int main() {
    while (true) {
        login();   // Ask for login every time after logging out
        menu();    // Run the menu based on the role
    }
    return 0;
}

