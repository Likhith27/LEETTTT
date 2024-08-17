class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word="";
        string ans="";
        while(ss>>word)
        {
            ans = word + " " + ans;
        }
        return ans.substr(0,ans.size()-1);
    }
};