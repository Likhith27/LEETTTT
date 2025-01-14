class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> result;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) { // Left-to-right for even rows
                for (int j = 0; j < m; j++) {
                    if ((i + j) % 2 == 0) { // Include cell if (i + j) % 2 == 0
                        result.push_back(grid[i][j]);
                    }
                }
            } else { // Right-to-left for odd rows
                for (int j = m - 1; j >= 0; j--) {
                    if ((i + j) % 2 == 0) { // Include cell if (i + j) % 2 == 0
                        result.push_back(grid[i][j]);
                    }
                }
            }
        }

        return result;
    }
};
