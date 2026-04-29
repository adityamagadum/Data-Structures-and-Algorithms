/*
Minimum Days to Make Bouquets

Given bloomDay[] where bloomDay[i] = day flower i blooms.
We need to make m bouquets, each using k adjacent flowers.
If total flowers < m*k → return -1 (not possible).
Find minimum day where bouquets >= m.
Example:
bloomDay = [1,10,3,10,2], m = 3, k = 1 → answer = 3
a[o]=1-> represents the flower blon is on day one 
a[1]=10a-> represents the flower blon is on day ten
the flower are planted one fdater another we can make the bokque by consuctive flkower not by random  
if i take day 3 
a[0],a[2],a[4] has blown k=1 (minimum  flower in an boque)
and as k=1 we can make 3 boque
if the k=2 then boque was not possible becz the flower should be conscative
*/
//optimal by binary search
#include<bits/stdc++.h>
using namespace std;

class MiniNoOfDaysForBOuqets
{
    public:
    int  possibleorNOT(vector<int>& v1,int day,int m,int k){
        int cnt=0;
        int NoOfBq=0;
        for(int i=0;i<v1.size();i++){
            if(v1[i]<=day){
                cnt++;
            }
            else{
                NoOfBq+=(cnt/k);
                cnt=0;
            }
        }
        NoOfBq+=(cnt/k);
        return NoOfBq;
    }
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
    int minelement(vector<int>& v) {
        int n=v.size();
        int min=v[0];
        for(int i=1;i<n;i++){
            if(v[i]<min){
                min=v[i];
            }
        }
        return min;
    }
    int mindays(vector<int>& v1, int m, int k){
        int n=v1.size();

        if(n<m*k) return -1;

        int low=minelement(v1);
        int high=maxelement(v1);

        int ans=0;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(possibleorNOT(v1,mid,m,k)>=m){
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
    MiniNoOfDaysForBOuqets s1;
    vector<int> v1={1,10,3,10,2};
    int m=3;
    int k=1;
     int ans=s1.mindays(v1,m,k);
     cout<< ans;
    
    return 0;
}
