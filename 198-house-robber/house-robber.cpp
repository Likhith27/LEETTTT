class Solution {
public:
    int n;
    vector<int>dp;
    int f(int ind,vector<int>& nums)
    {
        //pruning case
        if(ind<0)return 0; 
        //base case
        if(ind==0)return nums[ind]; 
        //cache check
        if(dp[ind]!=-1)return dp[ind];
        //compute
        int not_take = f(ind-1,nums);
        int take = f(ind-2,nums)+nums[ind];
        //save and return
        return dp[ind]=max(take,not_take);
    }
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        dp.assign(n+1,-1);
        return f(n-1,nums);
    }
};