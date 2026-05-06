// Book Allocation Problem:
// We are given books with different numbers of pages and some students.
// Each student must get at least one book, and books assigned to a student must be continuous.
// The goal is to distribute the books so that the maximum pages assigned to any student is minimized.
// arr[]={12,34,67,90} students=2;
// one way 12/ 34+67+90 =max(12,191)=191
// otherway 12+34/67+90=max=(46,157)=157
// 12+34+67/90=max(113,90)=113
// min(191,157,113)=113

#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    bool POssibleORNot(vector<int>& v1,int Noofstudents,int mid){
        int allocStu=1;int pages=0;
        int n=v1.size();
        for(int i=0;i<n;i++){
            if(v1[i]>mid) return false;
            if(pages+v1[i]>mid){
                allocStu+=1;
                pages=v1[i];
            }
            else{
                pages+=v1[i];
            }
        }
        if(allocStu>Noofstudents) return false;
        else return true;

    }
    int maxpages(vector<int>& v1,int Noofstudents){
        int low=*max_element(v1.begin(), v1.end());
        int high=accumulate(v1.begin(), v1.end(), 0);
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(POssibleORNot(v1,Noofstudents,mid)){
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
    vector<int> v1={12,34,67,90};
    solution s1;
    cout<<s1.maxpages(v1,2);

    return 0;
}