class Solution {
public:
    void f(int ind,string &digits,string &temp,vector<string>&map,vector<string>&ans)
    {
        if(digits.size()==0)
            return;
        if(ind == digits.size())
        {
            ans.push_back(temp);
            return;
        }
        string letters = map[digits[ind]-'0'];
        for(char ch:letters)
        {
            temp += ch;
            f(ind+1,digits,temp,map,ans);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        vector<string>map = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string temp;
        f(0,digits,temp,map,ans);
        return ans;
    }
};