
// Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

// Note that it is the kth smallest element in the sorted order, not the kth distinct element.

// You must find a solution with a memory complexity better than O(n2).

 

// Example 1:

// Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
// Output: 13
// Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
// Example 2:

// Input: matrix = [[-5]], k = 1
// Output: -5
 










#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int upperBound(vector<int>& arr, int target) {

        int low = 0;
        int high = arr.size() - 1;

        int ans = arr.size();

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (arr[mid] > target) {

                ans = mid;
                high = mid - 1;
            }
            else {

                low = mid + 1;
            }
        }

        return ans;
    }

    int countSmallEqual(vector<vector<int>>& matrix, int mid) {

        int count = 0;

        for (int i = 0; i < matrix.size(); i++) {
            count += upperBound(matrix[i], mid);
        }

        return count;
    }

    int kthSmallest(vector<vector<int>>& mat, int k) {

        int r = mat.size();
        int c = mat[0].size();

        int low = mat[0][0];
        int high = mat[0][c - 1];

        // Find minimum and maximum element
        for (int i = 0; i < r; i++) {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][c - 1]);
        }

        // Binary Search on Answer
        while (low <= high) {

            int mid = low + (high - low) / 2;

            int cnt = countSmallEqual(mat, mid);

            if (cnt < k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return low;
    }
};

int main() {

    vector<vector<int>> mat = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };

    int k = 8;

    Solution obj;

    int ans = obj.kthSmallest(mat, k);

    cout << "Kth Smallest Element: " << ans << endl;

    return 0;
}