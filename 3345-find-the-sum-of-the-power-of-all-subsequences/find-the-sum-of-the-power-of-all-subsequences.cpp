class Solution {
public:
    const int mod = 1e9+7;
    int n;
    int dp[201][201];
    int rec(int level,int k,vector<int>&arr)
    {
        //pruning
        // if(level>=n)
        // {
        //     return 0;
        // }
        //base case
        if(level==n)
        {
            if(k==0)return 1;
            else return 0;
        }
        //cache check
        if(dp[level][k]!=-1)return dp[level][k];
        //compute
        int ans =0;
        int not_take = rec(level+1,k,arr)%mod;
        int take=0;
        if(k>=arr[level])take = rec(level+1,k-arr[level],arr)%mod;

        //save and return 
        return dp[level][k]= ((take)%mod+(2*not_take)%mod)%mod;//most important concept whenever subset of subset think of the contribution technique and use 2* or 3^n-1 or as vivek said (very very important)
    }
    int sumOfPower(vector<int>& nums, int k) {
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,k,nums)%mod;
    }
};