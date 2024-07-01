class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &dist, int curr){
        dist[node]=curr;
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,dist,curr+1);
            }
        }
    }
    int diameter(vector<int> adj[], int n){
        vector<int> vis(n,0),dist(n,0);
        dfs(0,adj,vis,dist,0);
        int maxi=0;
        int leafnode=0;
        for(int i=0; i<n; i++){
            if(dist[i]>maxi){
                maxi=dist[i];
                leafnode=i;
            }
        }
        vector<int> vis1(n,0),dist1(n,0);
        dfs(leafnode,adj,vis1,dist1,0);
        maxi=0;
        for(int i=0; i<n; i++){
            if(dist1[i]>maxi){
                maxi=dist1[i];
            }
        }
        return maxi;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size()+1;
        int m=edges2.size()+1;
        vector<int> g1[n],g2[m];
        for(auto it:edges1){
            int u=it[0],v=it[1];
            g1[u].push_back(v);
            g1[v].push_back(u);
        }
        for(auto it:edges2){
            int u=it[0],v=it[1];
            g2[u].push_back(v);
            g2[v].push_back(u);
        }
        int dia1=diameter(g1,n);
        int dia2=diameter(g2,m);
    
        return max({dia1,dia2,(dia1+1)/2+1+(dia2+1)/2}); 
    }
};