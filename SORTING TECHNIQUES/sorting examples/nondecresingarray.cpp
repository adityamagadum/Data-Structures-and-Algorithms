#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkPossibility( vector<int>& nums) {
        int n=nums.size();
        int cnt=0;

        for(int i=0;i<n-1;i++)
        {
            if(nums[i]<=nums[i+1]){

            }
            else{
                cnt++;
            }
        }
        
        if(cnt==1) return true;
        else return false;
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