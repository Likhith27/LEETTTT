class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        for(int i=1;i<=n-1;i++)
        {
            for(auto i:times)
            {
                int u = i[0];
                int v = i[1];
                int t = i[2];
                if(dist[u]!=INT_MAX and t+dist[u]<dist[v])
                {
                    dist[v]=t+dist[u];
                }
            }
        }
        int maxi=0;
        for(int i=1;i<=n;i++)
        {
            maxi = max(maxi,dist[i]);
        }
        if(maxi==INT_MAX)
            return -1;
        return maxi;
    }
};