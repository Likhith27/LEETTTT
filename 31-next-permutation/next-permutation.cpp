class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        //three steps approach
        //1. break point
        //2. swap the ind
        //3. reverse the arr from [ind+1,n-1]
        

        //find the break point
        int ind=-1;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                ind=i;
                break;
            }
        }

        //edge case(strictly decreasing)
        if(ind==-1){
            reverse(nums.begin(),nums.end());
            return;
        }

        //step-2 swap the index (main step)
        for(int i=n-1;i>ind;i--)
        {
            if(nums[i]>nums[ind])
            {
                swap(nums[i],nums[ind]);
                break;
            }
        }

        //step-3 (reverse from ind+1 to end)
        reverse(nums.begin()+ind+1,nums.end());
        // return nums;
    }
};