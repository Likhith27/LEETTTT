class Solution {
public:
    void f(int ind,int target,vector<int>&nums,vector<int>&ds,vector<vector<int>>&dp)
    {
        if(ind==nums.size())
        {
            if(target==0)
                dp.push_back(ds);
            return;
        }
        if(nums[ind]<=target)
        {
            ds.push_back(nums[ind]);
            f(ind,target-nums[ind],nums,ds,dp);
            ds.pop_back();
        }
        f(ind+1,target,nums,ds,dp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>dp;
        vector<int>ds;
        f(0,target,candidates,ds,dp);
        return dp;
    }
};