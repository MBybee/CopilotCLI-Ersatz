/*******************************
 * Always check your sources
 *******************************/ 

#include <iostream>
#include "copilot_connect.h"

int main() {
    std::cout << "Welcome to Copilot Assistant! \n";
    
    std::string userQuery;
    std::cout << "Enter your search query (or press Enter to use default): ";
    std::getline(std::cin, userQuery);  // Allows spaces in input

    // Use default query if the user didn't enter anything
    if (userQuery.empty()) {
        userQuery = "Tell me about Ken Thompsons Trusting Trust";
    }

    CopilotConnect::askCopilot(userQuery);
    return 0;
}
