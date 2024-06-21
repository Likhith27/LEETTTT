class Solution {
private:
void f(int ind,vector<int> &nums,vector<int> &ds,vector<vector<int>> &ans)
    {
        ans.push_back(ds);
        for(int i=ind;i<nums.size();i++)
        {
            if(i!=ind && nums[i]==nums[i-1])
                continue;
            ds.push_back(nums[i]);
            f(i+1,nums,ds,ans);
            ds.pop_back();
        }
    }
public:
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        f(0,nums,ds,ans);
        return ans;



        
        // int n = nums.size();
        // vector<vector<int>> v(1<<n);
        // for(int i=0;i<(1<<n);i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         if(i&(1<<j))
        //             v[i].push_back(nums[j]);
        //     }
        // }
        // vector<vector<int>> m;
        // set<vector<int>>s(v.begin(),v.end());
        // for(auto i:s)
        // {
        //     m.push_back(i);
        // }
        // return m;
        
    }
};