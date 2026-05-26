// Remove Outermost Parentheses


// 23

// Problem Statement: A valid parentheses string is defined by the following rules:

// It is the empty string "".
// If A is a valid parentheses string, then so is "(" + A + ")".
// If A and B are valid parentheses strings, then A + B is also valid.

// A primitive valid parentheses string is a non-empty valid string that cannot be split into two or more non-empty valid parentheses strings.

// Given a valid parentheses string s, your task is to remove the outermost parentheses from every primitive component of s and return the resulting string.
// Examples
// Example 1:
// Input:
//  s = "((()))"
// Output:
//  "(())"
// Explanation:
//  The input string is a single primitive: "((()))".  
// Removing the outermost layer yields: "(())".

// Example 2:
// Input:
//  s = "()(()())(())"
// Output:
//  "(()())()"
// Explanation:
//  Primitive decomposition: "()" + "(()())" + "(())"  
// After removing outermost parentheses: "" + "()()" + "()"
// Final result: "(()())()"


#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {

        string ans = "";
        int depth = 0;

        for(char ch : s) {

            // Opening bracket
            if(ch == '(') {

                // If not outermost bracket
                if(depth > 0) {
                    ans += ch;
                }

                depth++;
            }

            // Closing bracket
            else {

                depth--;

                // If not outermost bracket
                if(depth > 0) {
                    ans += ch;
                }
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    string s;

    cout << "Enter parentheses string: ";
    cin >> s;

    string result = obj.removeOuterParentheses(s);

    cout << "Result: " << result << endl;

    return 0;
}