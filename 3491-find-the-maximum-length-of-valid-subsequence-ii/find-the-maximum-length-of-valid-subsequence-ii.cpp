class Solution {
public:
    int n;
    map<int,vector<int>>mp;
    int rec(int ind,int prev,vector<int>&nums,int k,vector<vector<int>> &dp)
    {
        if(dp[ind][prev]!=-1)return dp[ind][prev];
        int ans=2;
        auto y = lower_bound(mp[nums[ind]%k].begin(),mp[nums[ind]%k].end(),prev);
        if(y!=mp[nums[ind]%k].begin())
        {
            y--;
            int m = *y;
            ans = max(ans,1+rec(prev,m,nums,k,dp));
        }
        return dp[ind][prev]=ans;
    }
    int maximumLength(vector<int>& nums,int k) {
        n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        // int k =2;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]%k].push_back(i);
        }
        int ans=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                ans = max(ans,rec(i,j,nums,k,dp));
            }
        }
        return ans;
    }
};