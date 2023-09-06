class Solution {
public:
    int f(int ind,int amount,vector<int>&coins,vector<vector<int>>&dp)
    {
        if(amount==0)
            return 0;
        if(ind<0 || amount<0)
            return INT_MAX-1;
        if(dp[ind][amount]!=-1)
            return dp[ind][amount];
        int take=0,not_take=0;
        not_take = f(ind-1,amount,coins,dp);
        take =1+ f(ind,amount-coins[ind],coins,dp);
        return dp[ind][amount] = min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans = f(n-1,amount,coins,dp);
        if(ans<INT_MAX-1)
            return ans;
        else
            return -1;
    }
};