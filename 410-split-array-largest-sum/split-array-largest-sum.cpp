class Solution {
public:
    int check(int x,int k,vector<int>&nums){
        int sum=0;
        int cnt =0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]<=sum)
            {
                sum-=nums[i];
            }
            else
            {
                cnt++;
                sum=x;
                if(nums[i]<=sum)
                    sum-=nums[i];
                else
                    return 0;
            }
        }
        return cnt<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *min_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(check(mid,k,nums)){
                ans =mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }
};