// Example 1:
// Input:
//  s = "xyx"
// Output:
//  1
// Explanation:
//  The substrings with non-zero beauty are:
// "xyx" → frequencies: x:2, y:1 → beauty = 2 - 1 = 1
// "xy" → x:1, y:1 → beauty = 0
// "yx" → y:1, x:1 → beauty = 0
// "x" or "y" → beauty = 0
// Total sum = 1 (from "xyx") = 1

// Example 2:
// Input:
//  s = "aabcbaa"
// Output:
//  17
// Explanation:
//  Various substrings such as "aabc", "bcba", etc., have non-zero beauty values. Summing all gives 17.


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int sum=0;

        for(int i=0;i<n;i++){
            unordered_map<char,int> freq;
            for(int j=i;j<n;j++){
                freq[s[j]]++;

                int maxi=0;
                int mini=INT_MAX;

                for(auto it: freq){
                    maxi=max(maxi,it.second);
                    mini=min(mini,it.second);
                }
                sum+=(maxi-mini);
            }
        }
        return sum;
    }
};
int main()
{
    string s;
    Solution s1;

    cout << "Enter string: ";
    getline(cin, s);

    cout << "Integer value = " <<s1.beautySum(s);

    return 0;
}