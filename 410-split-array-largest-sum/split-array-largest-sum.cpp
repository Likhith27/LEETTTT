class Solution {
public:
    int check(int sum,vector<int>&nums,int k)
    {
        int n=nums.size();
        int painters_spawned=0;
        int last_sum=0;
        for(int i=0;i<n;i++)
        {
            if(last_sum>=nums[i])
                last_sum -= nums[i];
            else
            {
                painters_spawned++;
                last_sum=sum;
                if(last_sum>=nums[i])
                    last_sum -= nums[i];
                else
                    return 0;
            }
        }
        return painters_spawned<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1)
            return 0;
        int low=1;
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(check(mid,nums,k))
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