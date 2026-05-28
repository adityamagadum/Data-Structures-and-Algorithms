
// # Reverse Words in a String
// Given a string `s`, reverse the order of words.
// * Words are separated by spaces.
// * Remove extra spaces in output.
// ## Example
// Input:
// "the sky is blue"
// Output:
// "blue is sky the"
// ## Example 2
// Input:
// ```text
// "  hello   world  "
// Output:
// "world hello"
//remove unwanted space 

#include<bits/stdc++.h>
using namespace std;
class Solution { 
public:
    string reverseWords(string s) {
        string result = "";
        int i = s.size() - 1;

        while(i >= 0) {

            // skip spaces
            while(i >= 0 && s[i] == ' ') {
                i--;
            }

            if(i < 0) {
                break;
            }

            int end = i;

            // move till start of word
            while(i >= 0 && s[i] != ' ') {
                i--;
            }

            string word = s.substr(i + 1, end - i);

            // add space only after first word
            if(!result.empty()) {
                result += " ";
            }

            result += word;
        }

        return result;
    }
};
int main(){
    Solution s1;
    string s;
    cout<<"Enter the string:";
    getline(cin, s);
    cout<<s1.reverseWords(s);


}