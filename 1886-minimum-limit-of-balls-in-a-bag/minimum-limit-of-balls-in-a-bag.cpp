class Solution {
public:
    int check(int x,int k,vector<int>&nums)
    {
        int n = nums.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int res = nums[i]/x;
            cnt+=(res-1);
            if(nums[i]%x!=0)cnt++;
        }
        return cnt<=k;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        int k = maxOperations;
        int low = 1;
        int high = 1e9+7;
        int ans = INT_MAX;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(check(mid,k,nums))
            {
                ans=mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
    }
};