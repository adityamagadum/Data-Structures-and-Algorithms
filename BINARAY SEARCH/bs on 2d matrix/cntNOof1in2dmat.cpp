// Given a m x n binary matrix mat, find the 0-indexed position of the row that contains the maximum count of ones, and the number of ones in that row.

// In case there are multiple rows that have the maximum count of ones, the row with the smallest row number should be selected.

// Return an array containing the index of the row, and the number of ones in it.

 

// Example 1:

// Input: mat = [[0,1],[1,0]]
// Output: [0,1]
// Explanation: Both rows have the same number of 1's. So we return the index of the smaller row, 0, and the maximum count of ones (1). So, the answer is [0,1]. 
// Example 2:

// Input: mat = [[0,0,0],[0,1,1]]
// Output: [1,2]
// Explanation: The row indexed 1 has the maximum count of ones (2). So we return its index, 1, and the count. So, the answer is [1,2].
// Example 3:

// Input: mat = [[0,0],[1,1],[0,0]]
// Output: [1,2]
// Explanation: The row indexed 1 has the maximum count of ones (2). So the answer is [1,2].
 










#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    int lowerbound(vector<int>& arr, int n, int x) {

        int low = 0;
        int high = n - 1;

        int ans = n;

        while(low <= high) {

            int mid = (low + high) / 2;

            if(arr[mid] >= x) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }

    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {

        int cnt_max = 0;
        int index = 0;

        int n = mat.size();

        for(int i = 0; i < n; i++) {

            // Sort current row
            sort(mat[i].begin(), mat[i].end());

            int m = mat[i].size();

            // Count number of 1s
            int cnt_ones = m - lowerbound(mat[i], m, 1);

            // Update answer
            if(cnt_ones > cnt_max) {
                cnt_max = cnt_ones;
                index = i;
            }
        }

        return {index, cnt_max};
    }
};

int main() {

    // Input matrix
    vector<vector<int>> mat = {
        {0, 1},
        {1, 0}
    };

    Solution obj;

    vector<int> ans = obj.rowAndMaximumOnes(mat);

    cout << "Row Index with Maximum Ones: " << ans[0] << endl;
    cout << "Maximum Number of Ones: " << ans[1] << endl;

    return 0;
}