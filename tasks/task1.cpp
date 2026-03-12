// Task #1 Using regex library create a program that censors animal names in a text:
//      - The program should scan a block of text
//      - Every occurrence of the words "cat", "dog", or "mouse" should be replaced with "***"
//      - The replacement should affect all occurrences in the text
//      - After replacing, print the modified text
//
// Example text:
// "The cat chased the mouse while the dog watched. Later the cat and the dog fell asleep."
//
// Expected output:
// "The *** chased the *** while the *** watched. Later the *** and the *** fell asleep."

#include <iostream>
#include <regex>
#include <string>

int main() {

    std::string text = "The cat chased the mouse while the dog watched. Later the cat and the dog fell asleep.";

    std::regex pattern(R"(cat|dog|mouse)");

    std::string result = std::regex_replace(text, pattern, "***");

    std::cout << "Modified text: " << result << std::endl;

    return 0;
}