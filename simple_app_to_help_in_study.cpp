#include <iostream>
#include <map>
#include <vector>
#include <iomanip>

class StudyApplication {
private:
    std::map<std::string, std::vector<std::string>> subjects;

public:
    void addNote(const std::string& subject, const std::string& note) {
        subjects[subject].push_back(note);
    }

    void viewNotes() const {
        if (subjects.empty()) {
            std::cout << "No subjects or notes available.\n";
            return;
        }

        for (const auto& entry : subjects) {
            std::cout << "Subject: " << entry.first << std::endl;
            std::cout << "Notes:\n";

            for (const auto& note : entry.second) {
                std::cout << "  - " << note << std::endl;
            }

            std::cout << std::endl;
        }
    }
};

int main() {
    StudyApplication studyApp;
    int choice;

    do {
        std::cout << "Study Application Menu\n";
        std::cout << "1. Add Note\n";
        std::cout << "2. View Notes\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string subject, note;
                std::cout << "Enter subject: ";
                std::cin >> subject;

                std::cout << "Enter note: ";
                std::cin.ignore();  // Clear newline from buffer
                std::getline(std::cin, note);

                studyApp.addNote(subject, note);
                std::cout << "Note added successfully!\n";
                break;
            }
            case 2:
                studyApp.viewNotes();
                break;
            case 3:
                std::cout << "Exiting Study Application.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
