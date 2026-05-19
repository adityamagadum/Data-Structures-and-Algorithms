// 74. Search a 2D Matrix
// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {

        int n = mat.size();        // number of rows
        int m = mat[0].size();    // number of columns

        int low = 0;
        int high = n * m - 1;

        while (low <= high) {

            int mid = (low + high) / 2;

            // Convert 1D index to 2D index
            int row = mid / m;
            int col = mid % m;

            if (mat[row][col] == target) {
                return true;
            }

            else if (mat[row][col] < target) {
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }

        return false;
    }
};

int main() {

    vector<vector<int>> mat = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target = 16;

    Solution obj;

    bool ans = obj.searchMatrix(mat, target);

    if (ans) {
        cout << "Target Found" << endl;
    }
    else {
        cout << "Target Not Found" << endl;
    }

    return 0;
}