class Solution {
public:

    void f(int level,string digits,string str,vector<string>&v,map<char,string>&mp)
    {
        //base case
        if(digits.size()==0)return;
        if(level==digits.size())
        {
            v.push_back(str);
            return;
        }
        //lccm
        //level choice check move
        string s = mp[digits[level]];
        for(char ch:s){
            str += ch;
            f(level+1,digits,str,v,mp);
            str.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        //str = "9999"
        vector<string>v;
        map<char,string>mp;
        int n = digits.size();
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        f(0,digits,"",v,mp);
        return v;
    }
};