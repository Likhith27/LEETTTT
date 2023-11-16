class Solution {
public:
    bool is_pal(string &s,int start,int end)
    {
        while(start<=end)
        {
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
    void f(int ind,string &s,vector<string>&temp,vector<vector<string>>&ans)
    {
        int n =s.size();
        if(ind == n)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<n;i++)
        {
            if(is_pal(s,ind,i))
            {
                temp.push_back(s.substr(ind,i-ind+1));
                f(i+1,s,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        vector<vector<string>>ans;
        f(0,s,temp,ans);
        return ans;
    }
};