#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <random>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::vector<int> original_seq;
    for (int i = 0; i < 10; ++i) {
        original_seq.push_back(std::rand() % 10);
    }

    std::cout << "a. Original sequence: ";
    for (int num : original_seq) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    std::vector<int> sorted_seq = original_seq;

    std::sort(sorted_seq.begin(), sorted_seq.end());
    std::cout << "b. Ascending order:   ";
    for (int num : sorted_seq) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    std::sort(sorted_seq.begin(), sorted_seq.end(), std::greater<int>());
    std::cout << "c. Descending order:  ";
    for (int num : sorted_seq) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    std::set<int> unique_set(original_seq.begin(), original_seq.end());

    std::cout << "d. Unique (Ascending): ";
    for (int num : unique_set) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    std::cout << "e. Unique (Descending):";
    for (auto it = unique_set.rbegin(); it != unique_set.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    int target;
    std::cout << "\nf. Enter a target number to find: ";
    std::cin >> target;

    auto it = std::find(original_seq.begin(), original_seq.end(), target);

    if (it != original_seq.end()) {
        int index = std::distance(original_seq.begin(), it);
        std::cout << "Target " << target << " found at index (0-based): " << index << "\n";
    } else {
        std::cout << "Target " << target << " was not found in the original sequence.\n";
    }

    return 0;
}

/*
Sample Output: 

a. Original sequence: 8 3 7 3 8 6 2 1 4 7 
b. Ascending order:   1 2 3 3 4 6 7 7 8 8 
c. Descending order:  8 8 7 7 6 4 3 3 2 1 
d. Unique (Ascending): 1 2 3 4 6 7 8 
e. Unique (Descending):8 7 6 4 3 2 1 

f. Enter a target number to find: 4
Target 4 found at index (0-based): 8
*/