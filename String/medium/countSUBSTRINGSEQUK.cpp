#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s, int k) {
        int n=s.size();
        int count=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int> freq;
            for(int j=i;j<n;j++){
                freq[s[j]]++;
            if(freq.size()==k)
                count++;
            }

        }
        return count;
        
    }
};

int main() {
    string s="pqpqs";
    int k=2;

    //cin >> s >> k;

    Solution obj;
    cout << obj.countSubstrings(s, k);

    return 0;
}