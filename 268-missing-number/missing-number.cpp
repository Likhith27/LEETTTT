class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //mex
        set<int>s(nums.begin(),nums.end());
        int mex=0;
        while(s.find(mex)!=s.end()){
            mex++;
        }
        return mex;
    }
};