class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lb = lower_bound(nums.begin(),nums.end(),target);
        if(lb==nums.end()||*lb!=target)
            return {-1,-1};
        
        auto up = upper_bound(nums.begin(),nums.end(),target);
        int x = lb-nums.begin();
        int y = up-nums.begin()-1;
        return {x,y};
    }
};