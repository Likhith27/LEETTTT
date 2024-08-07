class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n  = nums.size();
        vector<int>dp(n,1);
        vector<int>cnt(n,1);
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j] and dp[j]+1>dp[i])
                {
                    dp[i] = dp[j]+1;
                    cnt[i] = cnt[j];
                }
                else if(dp[j]+1==dp[i])
                {
                    cnt[i]+=cnt[j];
                }
            }
            maxi = max(maxi,dp[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(maxi==dp[i])
                ans+=cnt[i];
        }
        return ans;
    }
};