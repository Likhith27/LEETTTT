class Solution {
public:
    bool isAnagram(string s, string t) 
    {
       int n = size(s);
       int m = size(t);
       if(n!=m)
        return false;
       map<char,int>mp;
       for(int i=0;i<n;i++)
       {
           mp[s[i]]++;
       }
       for(auto i:t)
       {
           mp[i]--;
           if(mp[i]<0)
            return false;
       }
        return true;
       

        
    }
};