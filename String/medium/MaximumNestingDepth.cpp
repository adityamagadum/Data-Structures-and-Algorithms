// iven a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.

 

// Example 1:

// Input: s = "(1+(2*3)+((8)/4))+1"

// Output: 3

// Explanation:

// Digit 8 is inside of 3 nested parentheses in the string.

// Example 2:

// Input: s = "(1)+((2))+(((3)))"

// Output: 3

// Explanation:

// Digit 3 is inside of 3 nested parentheses in the string.

// Example 3:

// Input: s = "()(())((()()))"

// Output: 3

 






#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int maxDepth(string s) {
    int depth = 0;
    int maxi = 0;

    for (char ch : s) {
        if (ch == '(') {
            depth++;
            maxi = max(maxi, depth);
        }
        else if (ch == ')') {
            depth--;
        }
    }

    return maxi;
}

int main() {
    string s;

    cout << "Enter the string: ";
    getline(cin, s);

    cout << "Maximum Nesting Depth = " << maxDepth(s);

    return 0;
}