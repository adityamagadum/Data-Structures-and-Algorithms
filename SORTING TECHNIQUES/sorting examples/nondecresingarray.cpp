//665 LC NON-decresing Array
// Example 1:

// Input: nums = [4,2,3]
// Output: true
// Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
// Example 2:

// Input: nums = [4,2,1]
// Output: false
// Explanation: You cannot get a non-decreasing array by modifying at most one element.
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
               cnt++;

               if(cnt>1) return false;
               if(i==0|| nums[i-1]<= nums[i+1]){
                nums[i]=nums[i+1];
               }else{
                nums[i+1]=nums[i];
               }
            }
        }
        return true;

        
    }
};
int main(){
    Solution s1;
     int n;
    cin >> n;

    vector<int> v1(n);
    for(int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    bool ans=s1.checkPossibility(v1);

    cout<<ans;

    return 0;
}