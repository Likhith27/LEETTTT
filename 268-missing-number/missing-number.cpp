class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int k = (n*(n+1))>>1;
        int sum = accumulate(nums.begin(),nums.end(),0);
        return k-sum;
    }
};