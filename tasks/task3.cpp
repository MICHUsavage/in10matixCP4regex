// Task #3 Using regex library create a program that finds valid email addresses in a text:
//      - The email must follow the format: username@domain.com
//      - The username may contain letters, digits and underscores
//      - The domain must contain only lowercase letters
//      - The email must end with ".com"
//      - The program should scan a block of text and print all valid emails found
//      - Invalid emails should be ignored
//
// Text used for testing:
// "If you need help you can email support_team@example.com or cntact the administrator at admin123@server.com. Some old contacts such as help-desk@company and marketing@mail are no longer valid.@domain."
#include <iostream>
#include <regex>
#include <string>

int main() {

    std::string text = "If you need help you can email support_team@example.com or cntact the administrator at admin123@server.com. Some old contacts such as help-desk@company and marketing@mail are no longer valid.@domain.";

    std::regex pattern(R"(\w+@[a-z]+\.com)");

    std::sregex_iterator it(text.begin(), text.end(), pattern);
    std::sregex_iterator end;

    if (it == end) {
        std::cout << "No valid emails found" << std::endl;
    } else {
        for (; it != end; ++it) {
            std::cout << "Valid email found: " << it->str() << std::endl;
        }
    }

    return 0;
}