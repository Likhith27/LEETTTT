class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // vector<int>lis;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>back(n,1);
        for(int i=0;i<n;i++)
        {
            back[i]=i;
            for(int j=0;j<i;j++)
            {
                
                if(nums[i]%nums[j]==0 and dp[j]+1>dp[i])
                {
                    dp[i] = 1+dp[j];
                    back[i] = j;
                }
            }
        }

        int ans=-1;
        int ind=-1;
        for(int i=0;i<n;i++)
        {
            if(ans<dp[i]){
                ans = dp[i];
                ind = i;
            }
        }
        vector<int>lis;
        lis.push_back(nums[ind]);

        while(back[ind]!=ind)
        {
            ind = back[ind];
            lis.push_back(nums[ind]);
        }
        reverse(lis.begin(),lis.end());
        return lis;

    }
};