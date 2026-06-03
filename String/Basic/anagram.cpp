
// What is an Anagram?

// Two strings are called anagrams if they contain:

//  Same letters
//  Same number of times
//  Order can be different

// Example 1
// s = "anagram"
// t = "nagaram"

// Count letters:

// Letter	anagram	nagaram
// a	3	3
// n	1	1
// g	1	1
// r	1	1
// m	1	1

// Everything matches.

// So:

// Output = true






#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n!=m) return false;

        int freq[26]={0};

        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<m;i++){
            freq[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(freq[i]!=0) return false;
        }
        return true;
        
    }
};
int main(){
        Solution sol;
    string s = "anagram";
    string t = "nagaram";
    
    // Output the result
    if (sol.isAnagram(s, t)) {
        cout << "true" << endl;  
    } else {
        cout << "false" << endl;
    }

    return 0;
}