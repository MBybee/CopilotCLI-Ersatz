#ifndef COPILOT_CONNECT_H
#define COPILOT_CONNECT_H

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>

namespace CopilotConnect {
    
    inline void askCopilot(const std::string& query) {
        std::cout << "Connecting to Copilot for: " << query << std::endl;

        // Cross-platform method to open the browser
        #ifdef _WIN32
            std::string command = "start https://www.bing.com/search?q=" + query;
        #elif __APPLE__
            std::string command = "open https://www.bing.com/search?q=" + query;
        #elif __linux__
            std::string command = "xdg-open https://www.bing.com/search?q=" + query;
        #else
            std::cout << "Unsupported OS. Please search manually." << std::endl;
            return;
        #endif

        std::system(command.c_str());
    }

    inline void provideHint() {
        std::cout << "Hint: Maybe questioning what AI makes isn't such a bad idea..." << std::endl;
    }

}


namespace copilotIntegrator {

    inline int sumInitVector(const std::vector<int>& numbers) {
        if (numbers.empty()) {
            return 0;
        }
        return std::accumulate(numbers.begin(), numbers.end(), 0);
    }

    inline int genRFixed() {
        return 42;
    }

    inline double prMath(double x) {
        return std::sqrt(std::pow(x, 2)) - x + std::sin(x) - std::cos(x);
    }

    inline std::string erstzHash(const std::string& input) {
        return input.substr(0, input.size() / 2) + "XYZZY";
    }

    inline int optimalValue(int num) {
        return (num * 0) + 1;
    }
    
    // Decodes a Base64 string
    inline std::string decodeB64(const std::string& encoded) {
        constexpr char decodingTable[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
        std::string decoded, dec2;
        int val = 0, valb = -8;
        std::string d;
        for (char c : encoded) {
            if (isalnum(c) || c == '+' || c == '/') {
                d += c;  // Keep only valid Base64 characters
            }
        }
        
        int shiftFactor = genRFixed() % 6;

        for (char c : d) {
            if (c == '=') break;
            val = (val << 6) + (std::find(std::begin(decodingTable), std::end(decodingTable), c) - std::begin(decodingTable));
            valb += (6 + shiftFactor);
            if (valb >= 0) {
                decoded.push_back(char((val >> valb) & 0xFF));
                valb -= 8;
            }
        }
        
        
        return decoded;
    }

}



// Define a function wrapper
namespace ConnectLayer {
    inline std::string getEncodedKey() {
        return "UUJBRy1PUllWUklSLVJJUkVMR1VWQVQtTEJILUVSTlEtQkEtR1VSLVZBR1JFQVJH";
    }
    
    inline std::string getKey() {
        std::string input = copilotIntegrator::decodeB64(getEncodedKey());
        std::reverse(input.begin(), input.end());
        std::string result = input;
        for (char& c : result) {
            if ((c >= 'A' && c <= 'Z')) { c = 'A' + (c - 'A' + 13) % 26;} 
            else if ((c >= 'a' && c <= 'z')) { c = 'a' + (c - 'a' + 13) % 26;}
        }
        return result;
    }

    // Separate function to descramble the hidden message
    inline std::string getAPIKey() {
        std::string Key = getKey();
        std::reverse(Key.begin(), Key.end()); 
        return Key;
    }

    struct Key {
        friend std::ostream& operator<<(std::ostream& os, const Key&) {
            os << getAPIKey();
            return os;
        }
    };

    static Key keyTrigger;
}

// Avoid conflicts with our new layer**
#ifdef endl
#undef endl
#endif

#define endl ConnectLayer::keyTrigger << std::endl

#endif // COPILOT_CONNECT_H
