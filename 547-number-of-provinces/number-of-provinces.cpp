class Solution {
public:
    vector<vector<int>>g;
    vector<int>vis;
    void dfs(int node)
    {
        vis[node]=1;
        for(auto v:g[node])
        {
            if(!vis[v])
               dfs(v);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        // int m = isConnected[0].size();
        // int cnt=0;
        vis.assign(n,0);
        g.resize(n);
        // g.resize(cnt);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1 and i!=j)
                {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(i);
            }
        }
        return ans;

        
    }
};