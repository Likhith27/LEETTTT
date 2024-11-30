class Solution {
public:
    int check(int x,int threshold,vector<int>&nums){
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            ans += ((nums[i]+x-1)/x);
        }
        return ans<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n= nums.size();
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(check(mid,threshold,nums)){
                ans =mid;
                high=mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }
};