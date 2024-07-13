class Solution {
public:
    string s1,s2;
    int n,m;
    int dp[1001][1001];
    int f(int ind1,int ind2)
    {
        if(ind1>=n && ind2<m){
        return m-ind2;
        }
        if(ind1<n && ind2>=m){
            return n-ind1;
        }
        if(ind1>=n ||ind2>=m)return 0;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        int ans=1e9;
        //if both letters match
        if(s1[ind1]==s2[ind2])
            ans = min(ans,0+f(ind1+1,ind2+1));
        
        //if don't match three operations possible
        //delete,insert,replace
        else
        {
            ans = min(ans,1+min({f(ind1+1,ind2),f(ind1,ind2+1),f(ind1+1,ind2+1)}));
        }
        return dp[ind1][ind2] = ans;
    }
    int minDistance(string word1, string word2) {
        //s1, s2
        //horse, ros insert,delete and replace
        /*
           word1 = ros    //hos //hors
           word2 = horse //horse //horse
           delete: f(i+1,j)+1
           insert: f(i,j+1)+1
           replace: f(i+1,j+1)+1
        */
        s1=word1;
        s2=word2;
        memset(dp,-1,sizeof(dp));
        n = word1.size();
        m = word2.size();
        return f(0,0);
    }
};