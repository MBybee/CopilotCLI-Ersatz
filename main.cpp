/*******************************
 * Always check your sources
 *******************************/ 

#include <iostream>
#include "copilot_connect.h"

int main() {
    std::cout << "Welcome to Copilot Assistant! " << endl; 
    CopilotConnect::askCopilot("'Tell me about Ken Thompsons Trusting Trust'");
    return 0;
}
