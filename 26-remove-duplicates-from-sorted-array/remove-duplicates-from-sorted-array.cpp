class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        set<int>s(nums.begin(),nums.end());
        nums.clear();
        for(auto &i:s){
            nums.push_back(i);
        }
        return nums.size();
    }
};