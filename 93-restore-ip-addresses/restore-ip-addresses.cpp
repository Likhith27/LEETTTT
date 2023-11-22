class Solution {
public:
    bool is_valid(string temp)
    {
        if(temp.size()>3 || temp.size()==0) 
            return false; 
        if(temp.size()>1 && temp[0]=='0')   
            return false; 
        if(temp.size() && stoi(temp)>255) 
            return false; 

        return true;
    }
    void f(int ind,int dots,string s,string temp,vector<string>&ans)
    {
        if(dots==3)
        {
            if(is_valid(s.substr(ind)))
                ans.push_back(temp+s.substr(ind));
            return;
        }
        int n = s.size();
        for(int i = ind;i<min(ind+3,n);i++)
        {
            if(is_valid(s.substr(ind,i-ind+1)))
            {
                temp.push_back(s[i]);
                temp.push_back('.');
                f(i+1,dots+1,s,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        
        f(0,0,s,"",ans);
        return ans;
    }
};