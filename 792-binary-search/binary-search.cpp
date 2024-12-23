class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = -1;
        int low = 0;
        int high = n-1;
        while(low<=high)
        {
            int mid = low +(high-low)/2;
            if(nums[mid]==target)
            {
                ans = mid;
                return ans;
            }
            else if(nums[mid]>target)
            {
                high = mid-1;
            }
            else
                low =mid+1;
        }
        return ans;
    }
};