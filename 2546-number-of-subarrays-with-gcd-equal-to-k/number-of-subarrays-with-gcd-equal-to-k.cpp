class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt=0;
        for(int i=0;i <n;i++)
        {
            int m=0;
            for(int j=i;j<n;j++)
            {
                m = __gcd(m,nums[j]);
                if(m==k)
                    cnt++;
            }
        }
        return cnt;
    }
};