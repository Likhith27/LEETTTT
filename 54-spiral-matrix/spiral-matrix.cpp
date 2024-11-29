class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int top = 0, bottom = n - 1, left = 0, right = m - 1;
    vector<int> v;

    while (left <= right && top <= bottom) {
        // Traverse from left to right along the top row
        for (int i = left; i <= right; i++) {
            v.push_back(matrix[top][i]);
        }
        top++; // Move the top boundary down

        // Traverse from top to bottom along the right column
        for (int i = top; i <= bottom; i++) {
            v.push_back(matrix[i][right]);
        }
        right--; // Move the right boundary left

        if (top <= bottom) {
            // Traverse from right to left along the bottom row
            for (int i = right; i >= left; i--) {
                v.push_back(matrix[bottom][i]);
            }
            bottom--; // Move the bottom boundary up
        }

        if (left <= right) {
            // Traverse from bottom to top along the left column
            for (int i = bottom; i >= top; i--) {
                v.push_back(matrix[i][left]);
            }
            left++; // Move the left boundary right
        }
    }

    return v;
}

};