class Solution {
public:
    // int f(int ind,int amount,vector<int>&coins,vector<vector<int>> &dp)
    // {
    //     if(ind==0)
    //     {
    //         if(amount%coins[ind])
    //             return amount/coins[ind];
    //         else
    //             return 1e9;
    //     }
    //     if(dp[ind][amount]!=-1)
    //     {
    //         return dp[ind][amount];
    //     }   
       
    //     int not_take = 0 + f(ind-1,amount,coins,dp);
    //     int take = INT_MAX;
    //     if(amount>=coins[ind])
    //         take = 1+f(ind,amount-coins[ind],coins,dp);
    //     return dp[ind][amount] = min(take,not_take);
    // }
    // int coinChange(vector<int>& coins, int amount) {
    //     int n = coins.size();
    //     vector<vector<int>>dp(n,vector<int>(amount+1,0));
    //     // return f(n-1,amount,coins,dp);
    //     for(int i=0;i<n+1;i++)
    //     {
    //         for(int j=0;j<amount;j++)
    //         {
    //             if(i==0 || j==0)
    //                 dp[i][j] = (j==0)? 0:INT_MAX-1;
    //         }
    //     }
    //     for(int i=1;i<n+1;i++)
    //     {
    //         for(int j=0;j<amount+1;j++)
    //         {
    //             int not_take = dp[i-1][j];
    //             int take = INT_MAX;
    //             if(coins[i]<=j)
    //                 take = 1+dp[i][j-coins[i-1]];
    //             dp[i][j] = min(take,not_take);
    //         }
    //     }
    //     int ans = dp[n][amount];
    //     if(ans>=1e9)
    //         return -1;
    //     return ans;
    // }
    int help(vector<int>& coins, int amount, int n,vector<vector<int>>&h)
    {
        if(amount == 0) return 0;
        if(n < 0 || amount < 0) return INT_MAX-1;
        
        if(h[n][amount]!= -1) return h[n][amount];

        int one = help(coins,amount,n-1,h);
        int two = 1+help(coins,amount-coins[n],n,h);
      
        return h[n][amount] = min(one,two);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>h(coins.size()+1,vector<int>(amount+1,-1));
        int ans = help(coins,amount,coins.size()-1,h);
        return (ans < INT_MAX-1)?ans:-1;
    }
};