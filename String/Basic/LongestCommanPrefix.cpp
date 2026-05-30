// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

 

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        int n=str.size();
        if(str.empty()) return"";

        sort(str.begin(),str.end());

        string first=str[0];
        string last=str[n-1];

        int minlen=min(first.size(),last.size());

        string ans="";

        for(int i=0;i<minlen;i++){
            if(first[i]!=last[i]){
                break;
            }
            ans+=first[i];
        }
        return ans;


        
    }
};
int main(){
int n;

    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs(n);

    cout << "Enter the strings:\n";

    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    Solution s1;

    string result = s1.longestCommonPrefix(strs);

    cout << "Longest Common Prefix: " << result << endl;

    return 0;

}