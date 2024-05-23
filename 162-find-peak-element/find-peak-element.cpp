class Solution {
public:
    int check(int ind,vector<int>&nums)
    {
        int n=nums.size();
        if(ind==n-1)return 1;
        return nums[ind]>nums[ind+1];
    }
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=-1;
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
        return ans;
    }
};