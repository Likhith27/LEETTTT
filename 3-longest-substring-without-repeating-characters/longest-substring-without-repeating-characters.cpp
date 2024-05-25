class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n=s.size();
        int maxi=0;
        int length=0;
        int j=0;
        map<char,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
            length++;
            while(mp[s[i]]>1)
            {
                mp[s[j++]]--;
                length--;
            }
            maxi = max(maxi,length);
        }
        return maxi;
    }
};