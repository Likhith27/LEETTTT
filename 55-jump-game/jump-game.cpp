class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int max_ind=0;
        for(int i=0;i<n;i++)
        {
            if(i>max_ind)return false;
            max_ind=max(max_ind,nums[i]+i);
        }
        return true;
    }
};