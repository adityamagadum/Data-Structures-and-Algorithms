//capcity to ship packages within D days 
// Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
// Output: 15<--mid value 
// Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
// 1st day: 1, 2, 3, 4, 5
// 2nd day: 6, 7
// 3rd day: 8
// 4th day: 9
// 5th day: 10

// Note that the cargo must be shipped in the order given, so using 
// a ship of capacity 14 and splitting the packages into parts 
// like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.


//optimal soln by binary search

#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    int NOofDays(vector<int>& v1,int cap){
        int n=v1.size();
        int days=1;int load=0;//cnt and sum and initaly day1 becz it will always go to else part only we are starting cap by max elem
        for(int i=0;i<n;i++){
            if(load+v1[i]>cap){
                days=days+1;
                load=v1[i];
            }
            else{
                load+=v1[i];
            }
        }
        return days;

    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);

        while(low<=high){
            int mid=low+(high-low)/2;

            int NoDays=NOofDays(weights,mid);

            if(NoDays<=days){
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
    vector<int> v1={1,2,3,4,5,6,7,8,9,10};

    solution s1;
    cout<<s1.shipWithinDays(v1,5);
    return 0;
}