class Solution {
public:
    vector<int>vis;
    void dfs(int node,vector<vector<int>>&g){
        vis[node]=1;
        for(auto v:g[node]){
            if(!vis[v])
                dfs(v,g);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
       int n = isConnected.size();
       int m = isConnected[0].size();
       vector<vector<int>>g(n+1);
       vis.assign(n+1,0);
       for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(isConnected[i][j]==1)
            {
                g[i+1].push_back(j+1);
                g[j+1].push_back(i+1);
            }
        }
       }
       int cnt=0;
       for(int i=1;i<=n;i++){
         if(!vis[i]){
            dfs(i,g);
            cnt++;
         }
       }
       return cnt;

    }
};