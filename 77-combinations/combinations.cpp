class Solution {
public:
    void f(int ind,int n,int k,vector<int>&v,vector<vector<int>>&res)
    {
        if(v.size()==k)
        {
            res.push_back(v);
            return;
        }
        for(int i=ind;i<n+1;i++)
        {
            v.push_back(i);
            f(i+1,n,k,v,res);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>>ans;
        vector<int>v;
        f(1,n,k,v,ans);
        return ans;
    }
};