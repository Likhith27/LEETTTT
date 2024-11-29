class Solution {
public:
    
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        int ans =-1e9;
        for(int i=0;i<n;i++){
            if(i==0)dp[i]=nums[i];
            else
                dp[i] = max(dp[i-1]+nums[i],nums[i]);
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};