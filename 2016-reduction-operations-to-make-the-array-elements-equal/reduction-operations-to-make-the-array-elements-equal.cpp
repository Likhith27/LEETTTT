class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int j=n-1;j>0;j--)
        {
            if(nums[j-1]!=nums[j])
                ans += n-j;
        }
        return ans;
    }
};