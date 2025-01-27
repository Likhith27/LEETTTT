class Solution {
public:
    long long appealSum(string s) {
        long long n = s.length();
        long long ans = 0;//contribution of each character
        //in how many subarrays the character ch contains
        for(char ch='a';ch<='z';ch++)
        {
            long long tot = n*(n+1)/2;
            int last = -1;
            for(int i=0;i<n;i++)
            {
                if(s[i]==ch)
                {
                    long long len = i-last-1;
                    tot -= len*(len+1)/2;
                    last=i;
                }
            }
            long long len = n-last-1;
            tot -= len*(len+1)/2;
            ans += tot;
        }
        return ans;
    }
};