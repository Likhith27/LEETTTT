class Solution {
public:
    int n;
    int dp[201][20100];
    bool f(int ind,int sum,vector<int>&arr)
    {
        //pruning
        if(sum<0 || ind>n)
            return false;
        //base case
        if(ind==n){
            return sum==0;
        }
        //cache check
        if(dp[ind][sum]!=-1)return dp[ind][sum];
        //compute
        bool ans=0;
        //take or not take
        ans = ans|f(ind+1,sum,arr);
        if(sum>=arr[ind])
        ans = ans|f(ind+1,sum-arr[ind],arr);
        //save and return
        return dp[ind][sum]=ans;
    }
    bool canPartition(vector<int>& arr) {
        //s1+s2==sum;
        //s1==s2==sum/2
        n = arr.size();
        int sum = accumulate(arr.begin(),arr.end(),0);
        if(sum&1)return false;
        memset(dp,-1,sizeof(dp));
        return f(0,sum/2,arr);
    }
};