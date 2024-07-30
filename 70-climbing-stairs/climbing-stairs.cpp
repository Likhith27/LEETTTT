class Solution {
public:
    int dp[50];
    int rec(int ind)
    {
        //pruning 
        if(ind<=0)return 0;
        //base case 
        if(ind==1)return 1;
        if(ind==2)return 2;
        //cache check
        if(dp[ind]!=-1)return dp[ind];
        //compute
        int ans= rec(ind-1)+rec(ind-2);
        //save and return
        return dp[ind]=ans;
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return rec(n);
    }
};