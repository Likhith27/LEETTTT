class Solution {
public:
    vector<vector<int>>dp;
    int f(int row,int col,vector<vector<int>>&grid)
    {
        //pruning case
        if(row<0 || col<0||grid[row][col]==1)return 0;
        //base case
        if(row==0 and col==0)return 1;
        //cache check
        if(dp[row][col]!=-1)return dp[row][col];
        //compute
        int ans = 0;
        ans = f(row-1,col,grid)+f(row,col-1,grid);
        //save and return
        return dp[row][col]=ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        dp.assign(n+1,vector<int>(m+1,-1));
        return f(n-1,m-1,obstacleGrid);
    }
};