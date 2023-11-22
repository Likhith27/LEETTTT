class Solution {
public:
    void f(int ind,int n,vector<int>&nums,vector<int>&temp,vector<vector<int>>&v)
    {
        if(ind==n)
        {
            v.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        f(ind+1,n,nums,temp,v);
        temp.pop_back();
        f(ind+1,n,nums,temp,v);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>v;
        vector<int>temp;
        int n = nums.size();
        f(0,n,nums,temp,v);
        return v;
    }
};