class Solution {
public:
    long long int rev(long long int n)
    {
        long long int k;
        long long int ans=0;
        while(n)
        {
            k = n%10;
            ans = ans*10 + k;
            n /= 10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        int mod = 1e9+7;
        map<int,int>cnt;
        for (int& a : nums)
            res = (res + cnt[a - rev(a)]++) % mod;
        return res;
    }
};