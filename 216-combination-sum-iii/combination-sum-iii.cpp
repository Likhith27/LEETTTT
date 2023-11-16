class Solution {
public:
    void f(int ind,int sum,int k,int n,vector<int>&temp,vector<vector<int>>&ans)
    {
        if(sum == n and k==0)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<=9;i++)
        {
            if(i>n)
                break;
            
            temp.push_back(i);
            f(i+1,sum+i,k-1,n,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        vector<vector<int>> ans;
        f(1,0,k,n,temp,ans);
        return ans;
    }
};