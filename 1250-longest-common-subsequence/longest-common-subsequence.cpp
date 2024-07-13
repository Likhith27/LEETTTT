class Solution {
public:
    //form-3;
    string s1,s2;
    int n,m;
    int dp[1001][1001];
    int f(int ind1,int ind2)
    {
        //base case
        if(ind1>=n || ind2>=m)
            return 0;
        
        //cache check
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        
        //compute
        //match
        int ans =0;
        if(s1[ind1]==s2[ind2])
            ans = 1+f(ind1+1,ind2+1);
        else
            ans = max(f(ind1+1,ind2),f(ind1,ind2+1));
        
        //cache check
        return dp[ind1][ind2] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        s1 = text1;
        s2 = text2;
        n = s1.length();
        m = s2.length();
        return f(0,0);
    }
};