class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) 
    {
        int n = nums.size();
        string s;
        // for every i-th string we go to i-th number and add the opposite of ith number
        for(int i=0;i<n;i++)
        {
            if(nums[i][i]=='0')
                s+='1';
            else
                s+='0';

        }
        return s;
        
    }
};