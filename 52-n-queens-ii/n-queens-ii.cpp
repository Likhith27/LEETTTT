class Solution {
public:
void f(int col,vector<int>&left,vector<int>&lower,vector<int>&upper,vector<string>&temp,vector<vector<string>>&ans,int n)
    {
        if(col==n)
        {
            ans.push_back(temp);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(left[row]==0 and lower[row+col]==0 and upper[n-1+col-row]==0)
            {
                temp[row][col]='Q';
                left[row]=1;
                lower[row+col]=1;
                upper[n-1+col-row]=1;
                f(col+1,left,lower,upper,temp,ans,n);
                temp[row][col]='.';
                left[row]=0;
                lower[row+col]=0;
                upper[n-1+col-row]=0;

            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<string>>v;
        vector<string>temp(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            temp[i] =s;
        }
        vector<int>left(n,0),lower(2*n-1,0),upper(2*n-1,0);
        f(0,left,lower,upper,temp,v,n);
        set<vector<string>>t(v.begin(),v.end());
        return t.size();
    }
};