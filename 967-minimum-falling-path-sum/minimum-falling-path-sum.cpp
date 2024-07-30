class Solution {
public:
    vector<vector<int>>dp;
    int n,m;
    // int rec(int row,int col,vector<vector<int>>&grid)
    // {
    //     //pruning case
    //     if(col<0||col>=m)return 1e9;
    //     //base case;
    //     if(row==0)return grid[row][col];
    //     //cache check
    //     if(dp[row][col]!=-1)return dp[row][col];
    //     //compute
    //     int a = rec(row-1,col-1,grid)+grid[row][col];
    //     int b = rec(row-1,col+1,grid)+grid[row][col];
    //     int c = rec(row-1,col,grid)+grid[row][col];
    //     //save and return
    //     return dp[row][col]=min({a,b,c});
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        dp.assign(n, vector<int>(m, 1e9));  // Use 1e9 to represent a large number

        // Initialize the first row of dp
        for (int j = 0; j < m; ++j) {
            dp[0][j] = matrix[0][j];
        }

        // Fill the dp array
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int a = matrix[i][j] + dp[i-1][j];
                int b = j > 0 ? matrix[i][j] + dp[i-1][j-1] : 1e9;
                int c = j < m-1 ? matrix[i][j] + dp[i-1][j+1] : 1e9;
                dp[i][j] = min({a, b, c});
            }
        }

        // Find the minimum value in the last row
        int mini = 1e9;
        for (int j = 0; j < m; ++j) {
            mini = min(mini, dp[n-1][j]);
        }

        return mini;
    }
};