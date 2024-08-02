class Solution {
public:
  
    int maxSubArray(vector<int>& nums) 
    {
       int n= nums.size();
       int maxi=INT_MIN;
       vector<int>dp(n+1,0);
       for(int i=0;i<n;i++)
       {
         if(i==0)dp[i]=nums[i];
         else dp[i] = max(dp[i-1]+nums[i],nums[i]);
         maxi = max(maxi,dp[i]);
       }
       return maxi;
    }
};