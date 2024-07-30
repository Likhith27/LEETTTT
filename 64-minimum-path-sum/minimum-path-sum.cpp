class Solution {
public:
    vector<vector<int>>dp;
    int f(int row,int col,vector<vector<int>>&grid)
    {
        //pruning
        if(row<0||col<0)return 1e9;
        //base case
        if(row==0 and col==0)return grid[0][0];
        //cache check
        if(dp[row][col]!=-1)return dp[row][col];
        //compute 
        int left=f(row,col-1,grid)+grid[row][col];
        int down = f(row-1,col,grid)+grid[row][col];
        //save and return
        return dp[row][col]=min(left,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        dp.assign(n+1,vector<int>(m+1,-1));
        return f(n-1,m-1,grid);
    }
};