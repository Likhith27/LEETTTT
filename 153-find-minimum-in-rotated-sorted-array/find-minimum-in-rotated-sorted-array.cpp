class Solution {
public:
    int check(int ind,vector<int>& nums)
    {
        if(nums[ind]<nums[0])return 1;
        else return 0;
    }
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=0;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(check(mid,nums))
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return nums[ans];
    }
};