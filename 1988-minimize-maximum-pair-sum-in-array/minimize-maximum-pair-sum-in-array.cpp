class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int low = 0;
        int high = n-1;
        int k =0;
        while(low<=high)
        {
            k = max(k,nums[low]+nums[high]);
            low++;
            high--;
        }
        return k;
    }
};