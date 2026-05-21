// A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

// Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

// You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

// You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

 

// Example 1:



// Input: mat = [[1,4],[3,2]]
// Output: [0,1]
// Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.
// Example 2:



// Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
// Output: [1,1]
// Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    // Function to find row index of maximum element
    // in a particular column
    int findMaxIndex(vector<vector<int>>& mat, int n, int col) {

        int maxValue = -1;
        int index = -1;

        for(int i = 0; i < n; i++) {

            if(mat[i][col] > maxValue) {
                maxValue = mat[i][col];
                index = i;
            }
        }

        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        int low = 0;
        int high = m - 1;

        while(low <= high) {

            // Find middle column
            int mid = (low + high) / 2;

            // Find row having maximum element
            // in middle column
            int maxRowIdx = findMaxIndex(mat, n, mid);

            // Left element
            int left =
                (mid - 1 >= 0)
                ? mat[maxRowIdx][mid - 1]
                : -1;

            // Right element
            int right =
                (mid + 1 < m)
                ? mat[maxRowIdx][mid + 1]
                : -1;

            // Peak found
            if(mat[maxRowIdx][mid] > left &&
               mat[maxRowIdx][mid] > right) {

                return {maxRowIdx, mid};
            }

            // Move to left half
            else if(mat[maxRowIdx][mid] < left) {
                high = mid - 1;
            }

            // Move to right half
            else {
                low = mid + 1;
            }
        }

        return {-1, -1};
    }
};

int main() {

    vector<vector<int>> mat = {
        {1, 2, 3, 6},
        {4, 5, 8, 7},
        {3, 2, 1, 0}
    };

    Solution obj;

    vector<int> ans = obj.findPeakGrid(mat);

    cout << "Peak Element Position : ";

    cout << "[" << ans[0] << "," << ans[1] << "]";

    return 0;
}