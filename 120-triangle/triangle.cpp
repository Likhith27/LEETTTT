class Solution {
public:
    vector<vector<int>>dp;
    int rec(int row,int col,vector<vector<int>>&grid)
    {
        //pruning case
        if(col>row||col<0)return 1e9;
        //base case
        if(row==0)return grid[0][0];
        //cache check
        if(dp[row][col]!=-1)return dp[row][col];
        //compute
        int right = rec(row-1,col-1,grid)+grid[row][col];
        int left = rec(row-1,col,grid)+grid[row][col];
        //save and return
        return dp[row][col]=min(right,left);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        dp.assign(n, vector<int>(n, -1));
        int minTotal = 1e9;
        for (int col = 0; col < n; ++col) 
        {
            minTotal = min(minTotal, rec(n - 1, col, triangle));
        }
        return minTotal;
    }
};