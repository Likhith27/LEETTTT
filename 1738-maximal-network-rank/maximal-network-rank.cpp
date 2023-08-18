class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>>adj(n,vector<int>(n,0));
        vector<int>indegree(n,0);
        for(auto i:roads)
        {
            indegree[i[0]]++;
            indegree[i[1]]++;
            adj[i[0]][i[1]]=1;
            adj[i[1]][i[0]]=1;
        }
        int maxi = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int sum = indegree[i]+indegree[j]-adj[i][j];
                maxi = max(maxi,sum);
            }
        }
        return maxi;
    }
};