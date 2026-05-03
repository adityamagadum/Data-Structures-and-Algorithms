// Problem (Aggressive Cows):
// You are given positions of stalls (sorted or unsorted) on a number line.
// You need to place k cows in these stalls.
// Each stall can have only one cow.
// Your goal is to place the cows so that the minimum distance
// between any two cows is as large as possible (maximize spacing).
// Example:
// stalls = [1, 2, 4, 8, 9], k = 3
// One optimal placement → cows at [1, 4, 8]
// Distances = (4-1 = 3), (8-4 = 4)
// Minimum distance = 3 (this is maximum possible answer)

#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    bool CanWePlaceCow(vector<int>& v1,int dist,int NoCows){
        

        int n=v1.size();
        int CntCow=1;int last=v1[0];

        for(int i=1;i<n;i++){
            if(v1[i]-last>=dist){
                CntCow++;
                last=v1[i];

            }
 
        }
        if(CntCow>=NoCows) return true;
        else return false;

    }
    int MinmumDistace(vector<int>& v1,int NoCows){
        sort(v1.begin(),v1.end());
        int n=v1.size();
        int low=1;
        int high=(v1[n-1]-v1[0]);
        int ans=0;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(CanWePlaceCow(v1,mid,NoCows)){
                low=mid+1;
                ans=mid;
            }
            else{
                high=mid-1;
            }
        }
        return ans;

    }
};

int main(){
    solution s1;
    vector<int> v1={0,3,4,7,9,10};
    cout<<s1.MinmumDistace(v1,4);

    return 0;
}