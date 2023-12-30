class Solution {
public:
    bool makeEqual(vector<string>& words) {
        string s;
        int n = words.size();
        for(auto word:words)
            s+=word;
        vector<int>v(26,0);
        for(char c:s)
            v[c-'a']++;
        
        for(int i=0;i<v.size();i++)
        {
            if(v[i]%n!=0)
            {
                return false;
            }
        }
        return true;
    }
};