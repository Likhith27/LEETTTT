class Solution {
public:
    bool is_bipartite=true;
    vector<int>vis;
    void dfs(int node,int color,vector<vector<int>>& g)
    {
        vis[node]=color;
        for(auto v:g[node])
        {
            if(vis[v]==1)
             dfs(v,color^3,g);
            else if(vis[v]==vis[node])
                is_bipartite=false;
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vis.assign(n,1);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==1)
                dfs(i,1,graph);
        }
        return is_bipartite;
    }
};