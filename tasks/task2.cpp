// Task #2 Using regex library create a program that validates phone numbers:
//         - The number is divided in three blocks of 3 (XXX YYY ZZZ)
//         - Between the groups the user can use either a single whitespace or single -
//         - The Polish country code "+48" with a single whitespace may be added in the beginning but is not necessary

#include <iostream>
#include <regex>
#include <string>
#include <vector>

int main() {
    static const std::regex polish_phone(R"((\+48\s)?(\d{3}[\s-]?){2}\d{3})");

    std::vector<std::string> numbers = {
        "+48 123 456 789",
        "+48 123-456-789",
        "123456789",
        "500 600-700"
    };

    for (const auto& num : numbers) {
        if (std::regex_match(num, polish_phone)) {
            std::cout << "SUCCESS: " << num << "\n";
        }
    }
    return 0;
}

