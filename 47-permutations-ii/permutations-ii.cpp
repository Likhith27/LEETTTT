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
            if(i!=ind and nums[i]==nums[ind])
                continue;
            swap(nums[ind],nums[i]);
            f(ind+1,nums,ans);
            swap(nums[ind],nums[i]);
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(begin(nums), end(nums));
		
        vector<vector<int>> output;
        output.emplace_back(nums);
        while (next_permutation(begin(nums), end(nums))) {
            output.emplace_back(nums);
        }
        return output;
    }
};