class Solution {
public:
    void f(int open,int close,vector<string>&res,string str)
    {
        if(open==0 &&close==0)
        {
            res.push_back(str);
            return;
        }
        if(open>0)
            f(open-1,close,res,str+"(");
        if(close>0 && close>open)
        {
            f(open,close-1,res,str+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        f(n,n,res,"");
        return res;
        
    }
};