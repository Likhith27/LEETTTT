class Solution {
public:
    void f(int ind,vector<int> &nums,vector<vector<int>> &ans)
    {
        if(ind==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++)
        {
            swap(nums[ind],nums[i]);
            f(ind+1,nums,ans);
            swap(nums[ind],nums[i]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> v;
        f(0,nums,v);
        return v;
        // vector<vector<int>> temp;
        // do{
        //     temp.push_back(nums);
        // }
        // while(next_permutation(nums.begin(),nums.end()));
        // return temp;
    }
};