class Solution {
public:
    bool f(int l,int r,vector<int>nums)
    {
        sort(nums.begin(),nums.end());
        int k = nums[1]-nums[0];
        for(int i=2;i<nums.size();i++)
        {
            if(nums[i]-nums[i-1]!=k)
                return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>t;
        int m =l.size();
        for(int i=0;i<m;i++)
        {
            if(f(l[i],r[i],{nums.begin()+l[i],nums.begin()+r[i]+1}))
                t.push_back(true);
            else
                t.push_back(false);
        }
        return t;
    }
};