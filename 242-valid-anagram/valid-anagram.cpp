class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.length();
        int m = t.length();
        if(n!=m)return false;
        vector<int>v1(26,0),v2(26,0);
        for(char c:s)v1[c-'a']++;
        for(char c:t)v2[c-'a']++;
        if(v1==v2) return true;
        else return false;
    }
};