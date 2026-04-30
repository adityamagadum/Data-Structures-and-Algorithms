// Find the smallest divisor
// Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.
// Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).
// The test cases are generated so that there will be an answer.
// Input: nums = [1,2,5,9], threshold = 6
// Output: 5
// 1/5+2/3+5/5+9/5=6-->so we have to find the num after dividing and suming up it gives threshold value

//optimal code by binary search
#include<bits/stdc++.h>
using namespace std;
class solution{
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

    int ProductpLusSum(vector<int>& v1, int d){
        int n=v1.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=ceil((double)v1[i]/d);
        }
        
        return ans;
    };


    int samllestdivisor(vector<int>& v1, int threshold){
        int n=v1.size();
        int ans=0;

        int low=1;
        int high=maxelement(v1);
        while(low<=high){
            int mid=low+(high-low)/2;
            

            int temp=ProductpLusSum(v1,mid);

            if(temp<=threshold){
                ans=mid;
                high=mid-1;
            }
            else{
                 low=mid+1;
            }
        }
        return ans;
    }

};
int main(){
    solution s1;
    vector<int> v1={1,2,5,9};

    int ans =s1.samllestdivisor(v1,6);
    cout<<ans;
    return 0;
}