
// Problem Statement: Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
// A shift on s consists of moving the leftmost character of s to the rightmost position. 
// For example, if s = "abcde", then it will be "bcdea" after one shift.
// Example 1:
// Input:
//  s = "rotation", goal = "tionrota"
// Output:
//  true
// Explanation:
//  After multiple left shifts on "rotation", we get:
//     1st shift → "otationr"
//     2nd shift → "tationro"
//     3rd shift → "ationrot"
//     4th shift → "tionrota"
//     So the goal string can be obtained by rotating the original string.

// Example 2:
// Input:
//  s = "hello", goal = "lohelx"a
// Output:
//  false
// Explanation:
 
// Even after all possible rotations of "hello", we cannot form "lohelx" due to the presence of an extra character 'x'. Hence, it's not possible.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool rotateString(string s, string g) {
        if (s.size() != g.size()) {
            return false;
        }

        for (int i = 0; i < s.size(); i++) {
            string r = s.substr(i) + s.substr(0, i);

            if (r == g) {
                return true;
            }
        }

        return false;
    }
};
int main(){
    Solution sol;
    string s = "rotation";
    string goal = "tionrota";
    
    // Output the result
    if (sol.rotateString(s, goal)) {
        cout << "true" << endl;  
    } else {
        cout << "false" << endl;
    }

    return 0;

}