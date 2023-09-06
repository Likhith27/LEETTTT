class Solution {
public:
    // int f(int ind,vector<int>&nums,vector<int>&dp)
    // {
    //     if(ind==0)
    //         return nums[ind];
    //     if(dp[ind]!=-1)
    //         return dp[ind];
    //     int pick=0,nott=0;
    //     if(ind-2>=0)
    //         pick = nums[ind]+f(ind-2,nums,dp);
    //     else
    //         pick=0;
    //     if(ind-1>=0)
    //         nott = f(ind-1,nums,dp);
    //     else
    //         nott=0;
    //     return dp[ind]=max(pick,nott);
    // }
    int f(vector<int>& A, vector<int>& dp, int i) {
        if(i >= size(A)) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = max(f(A, dp, i+1), A[i] + f(A, dp, i+2));
    }
    int rob(vector<int>& nums) {
        // int n = nums.size();
        // vector<int>dp(n+1,-1);
        // return f(n-1,nums,dp);
        // return i < size(A) ? max(rob(A, i+1), A[i] + rob(A, i+2)) : 0;
        vector<int> dp(size(nums),-1);
        return f(nums, dp, 0);
    }
};