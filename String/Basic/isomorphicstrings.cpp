// Isomorphic String

// Problem Statement: Given two strings s and t, determine if they are isomorphic. Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.


// // Example 1
// Input:
//  s = "paper", t = "title"
// Output:
//  true
// Explanation:
//  The characters in "s" can be mapped one-to-one to characters in "t": 
// 'p' → 't', 'a' → 'i', 'e' → 'l', 'r' → 'e'
// Since the mapping is consistent and unique for each character, the strings are isomorphic.

// Example 2
// Input:
//  s = "foo", t = "bar"
// Output:
//  false
// Explanation:
//  'f' → 'b' is fine, 'o' → 'a' for the first 'o', But the second 'o' in "s" would need to map to 'r' in "t", which conflicts with the earlier mapping of 'o' → 'a'
// This inconsistency makes it impossible to convert "s" to "t" using a one-to-one character mapping.


#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    bool ISIsomorphic(string s,string t){

        int n=s.size();
        int m1[256]={-1};
        int m2[256]={-1};

        for(int i=0;i<n;i++){
            if(m1[s[i]]!=m2[t[i]]) return false;

            m1[s[i]]=i;
            m2[t[i]]=i;

        }
        return true;

    }

};
int main(){
    solution s1;
    string s="add";
    string t="egg";

    cout<<s1.ISIsomorphic(s,t);

    return 0;
}