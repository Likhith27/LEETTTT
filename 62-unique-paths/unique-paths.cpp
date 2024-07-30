class Solution {
public:
    vector<vector<int>>dp;
    int f(int row,int col)
    {
        //pruning case
        if(row<0 || col<0)return 0;
        //base case
        if(row==0 and col==0)return 1;
        //cache check
        if(dp[row][col]!=-1)return dp[row][col];
        //compute
        int ans = 0;
        ans = f(row-1,col)+f(row,col-1);
        //save and return
        return dp[row][col]=ans;
    }
    int uniquePaths(int m, int n) {
        dp.assign(n+1,vector<int>(m+1,-1));
        return f(n-1,m-1);
    }
};