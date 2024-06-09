class Solution {
public:
    int dp[2001][4001];
    int f(vector<int>&r,int ind,int sum){
        //base case
        if(ind==r.size())
        {
            return sum;
        }
        //cache check
        if(dp[ind][sum]!=-1)
        {
            return dp[ind][sum];
        }
        int npick=f(r,ind+1,sum);
        int pick=0;
        if(r[ind]>sum){
            pick=f(r,ind+1,sum+r[ind]);
        }
        return dp[ind][sum]=max(pick,npick);
    }
    int maxTotalReward(vector<int>& rewardValues) {
        memset(dp,-1,sizeof(dp));
        sort(rewardValues.begin(),rewardValues.end());
        return f(rewardValues,0,0);
    }
    
};