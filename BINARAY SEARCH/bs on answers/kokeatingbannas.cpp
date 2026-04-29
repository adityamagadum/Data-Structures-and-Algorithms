/*
Koko Eating Bananas (Binary Search on Arrays)
Given an array piles[] where each element is bananas in a pile, and h hours.
Koko eats at speed k bananas per hour, one pile per hour.
Time for each pile = (piles[i] + k - 1) / k.
Total time = sum of time for all piles.
We need minimum k such that total time <= h.
Search range: k from 1 to max(piles).
Use binary search to find smallest valid k.
Example: piles = [30,11,23,4,20], h = 6.
k = 23 works (total time = 6), k = 22 fails (total time = 7).
*/


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxelement(vector<int>& v) {
        int n=v.size();
        int max=v[0];
        for(int i=1;i<n;i++){
            if(v[i]>max){
                max=v[i];
            }
        }
        return max;
    }
    long long totalTime(vector<int>& v, int hr) {
        long long ans = 0;
        int n=v.size();
        for(int i=0;i<n;i++){
            ans += ((long long)v[i] + hr - 1) / hr;

        }
        return ans;  
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=maxelement(piles);
        int ans=INT_MIN;
        while(low<=high){
            int mid = low + (high - low) / 2;  
            long long totalhr=totalTime(piles,mid);
            if(totalhr<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
        
    }
};
int main(){
    Solution s1;
    vector<int> v1={3,6,7,11};

    int ans =s1.minEatingSpeed(v1,8);
    cout<<ans;
    return 0;
}
