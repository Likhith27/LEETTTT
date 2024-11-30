class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length();
        string ans="";
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' and cnt==0)cnt++;
            else if(s[i]=='(' and cnt>=1)
            {
                ans += s[i];
                cnt++;
            }
            else if(s[i]==')' and cnt>1)
            {
                ans+=s[i];
                cnt--;
            }
            else if(s[i]==')' and cnt==1)cnt--;
        }
        return ans;
    }
};