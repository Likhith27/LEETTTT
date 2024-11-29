class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>>v;
        sort(nums.begin(),nums.end());
        for(int j=0;j<n;j++)
        {
            int i=0;
            int k = n-1;
            while(i<j and j<k)
            {
                if(nums[i]+nums[j]+nums[k]==0)
                {
                    v.insert({nums[i],nums[j],nums[k]});
                    i++;
                    k--;
                }
                else if(nums[i]+nums[j]+nums[k]>0){
                    k--;
                }
                else
                    i++;
            }
        }
        vector<vector<int>>ans(v.begin(),v.end());
        return ans;
    }
};