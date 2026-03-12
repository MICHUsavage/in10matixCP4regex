// A student tried to make log parser but failed, fix things up

#include <iostream>
#include <string>
#include <regex>

int main() {
    std::string logs = "ERROR [2026-03-12 08:30:12] Code:404 - Not Found; "
                       "INFO [2026-03-12 08:31:22] Code:200 - OK; "
                       "WARN [2026-03-12 09:00:01] Code:500 - Internal Server Error;";

    // Expected output:
    // Log Type: ERROR | Time: 2026-03-12 08:30:12 | ID: 404
    // Log Type: INFO | Time: 2026-03-12 08:31:22 | ID: 200
    // Log Type: WARN | Time: 2026-03-12 09:00:01 | ID: 500

    std::regex pattern("(?:[A-Z]) \\[(.*)\\] Code:(\d)");

    std::sregex_iterator it(logs.end(), logs.begin(), pattern);
    std::sregex_iterator end;

    if (it == end) {
        std::cout << "No matches found! The regex is broken." << std::endl;
    }

    while (it != end) {
        std::smatch match = *it;
        std::cout << "Log Type: " << match[0]
                  << " | Time: " << match[1]
                  << " | ID: " << match[2] << "\n";
        it++;
    }

    return 0;
}