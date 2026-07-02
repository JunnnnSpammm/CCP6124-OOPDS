#include <iostream>
#include <map>
#include <string>
#include <algorithm>

int main() {
    std::multimap<std::string, std::string> advisoryMap;
    int numRelations = 0;

    std::cout << "How many advisory relationships do you want to enter? ";
    std::cin >> numRelations;
    std::cin.ignore();

    for (int i = 0; i < numRelations; ++i) {
        std::string lecturer, studentID;
        std::cout << "\nEnter details for relationship " << (i + 1) << ":\n";
        std::cout << "Lecturer Name: ";
        std::getline(std::cin, lecturer);
        std::cout << "Student ID: ";
        std::getline(std::cin, studentID);
        
        advisoryMap.insert({lecturer, studentID});
    }

    std::cout << "\n-----------------------------------------\n";
    std::cout << "Lecturers and Students (Ascending Order):\n";
    std::cout << "-----------------------------------------\n";
    if (advisoryMap.empty()) {
        std::cout << "No data available.\n";
    } else {
        for (const auto& pair : advisoryMap) {
            std::cout << "Lecturer: " << pair.first << " | Student ID: " << pair.second << "\n";
        }
    }

    std::cout << "\n-----------------------------------------\n";
    std::cout << "Lecturers and Students (Descending Order):\n";
    std::cout << "-----------------------------------------\n";
    if (advisoryMap.empty()) {
        std::cout << "No data available.\n";
    } else {
        for (auto it = advisoryMap.rbegin(); it != advisoryMap.rend(); ++it) {
            std::cout << "Lecturer: " << it->first << " | Student ID: " << it->second << "\n";
        }
    }

    std::cout << "\n-----------------------------------------\n";
    std::string searchLecturer;
    std::cout << "Enter the name of a lecturer to search for: ";
    std::getline(std::cin, searchLecturer);

    auto range = advisoryMap.equal_range(searchLecturer);

    std::cout << "\nStudents advised by " << searchLecturer << ":\n";
    if (range.first == range.second) {
        std::cout << "No records found for this lecturer.\n";
    } else {
        for (auto it = range.first; it != range.second; ++it) {
            std::cout << "- " << it->second << "\n";
        }
    }

    return 0;
}

/*
Sample Output: 

How many advisory relationships do you want to enter? 3

Enter details for relationship 1:
Lecturer Name: Willie
Student ID: 100132

Enter details for relationship 2:
Lecturer Name: Dr Goh
Student ID: 12432

Enter details for relationship 3:
Lecturer Name: Dr Ian
Student ID: 13332

-----------------------------------------
Lecturers and Students (Ascending Order):
-----------------------------------------
Lecturer: Dr Goh | Student ID: 12432
Lecturer: Dr Ian | Student ID: 13332
Lecturer: Willie | Student ID: 100132

-----------------------------------------
Lecturers and Students (Descending Order):
-----------------------------------------
Lecturer: Willie | Student ID: 100132
Lecturer: Dr Ian | Student ID: 13332
Lecturer: Dr Goh | Student ID: 12432

-----------------------------------------
Enter the name of a lecturer to search for: Willie

Students advised by Willie:
- 100132
*/