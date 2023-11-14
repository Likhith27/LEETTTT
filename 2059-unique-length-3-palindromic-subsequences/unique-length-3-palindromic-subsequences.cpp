class Solution {
public:
    int countPalindromicSubsequence(string inputString) {

        // string t = s;
        // reverse(s.begin(),s.end());
        // int n = s.size();
        // vector<vector<int>>dp(n,vector<int>(n,0));

        // for(int i=0;i<n;i++)
        //     dp[i][0]=0;
        // for(int j=0;j<n;j++)
        //     dp[0][j]=0;
        
       
        // for(int i=1;i<n;i++)
        // {
        //     for(int j=1;j<n;j++)
        //     {
        //         if(t[i-1]==s[j-1])
        //             dp[i][j] = 1+dp[i-1][j-1];
        //         else
        //             dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        //     }
        // }
        int result = 0;
        int firstIndex[26] = {[0 ... 25] = INT_MAX};
        int lastIndex[26] = {};

        for (int i = 0; i < inputString.size(); ++i) 
        {
            firstIndex[inputString[i] - 'a'] = min(firstIndex[inputString[i] - 'a'], i);
            lastIndex[inputString[i] - 'a'] = i;
        }
        for (int i = 0; i < 26; ++i)
            if (firstIndex[i] < lastIndex[i])
                result += unordered_set<char>(begin(inputString) + firstIndex[i] + 1, begin(inputString) + lastIndex[i]).size();
        return result;
    }
};