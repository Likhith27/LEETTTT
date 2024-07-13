class Solution {
public:
    string s1, s2;
    int n, m, k;
    vector<string> v;
    int dp[1001][1001];
    
    int f(int ind1, int ind2) {
        // base case
        if (ind1 >= n || ind2 >= m)
            return 0;
        
        // cache check
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        
        // compute
        int ans = 0;
        if (s1[ind1] == s2[ind2])
            ans = 1 + f(ind1 + 1, ind2 + 1);
        else
            ans = max(f(ind1 + 1, ind2), f(ind1, ind2 + 1));
        
        // cache the result
        return dp[ind1][ind2] = ans;
    }
    int minDistance(string word1, string word2) {
         //n+m-2*lcs(s1,s2)
         s1=word1;
         s2=word2;
         n = s1.length();
         m = s2.length();
         memset(dp,-1,sizeof(dp));
         int k = f(0,0);
         return n+m-2*k;
    }
};