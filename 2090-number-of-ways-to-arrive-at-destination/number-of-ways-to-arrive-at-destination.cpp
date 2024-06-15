// #define int long long
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long int>dis(n,1e18);
        vector<long long int>paths(n,0);
        vector<int>vis(n,0);
        vector<vector<pair<int,int>>>g(n);
        const int mod = 1e9+7;
        for(auto edge:roads)
        {
            g[edge[0]].push_back({edge[1],edge[2]});
            g[edge[1]].push_back({edge[0],edge[2]});
        }
        priority_queue<pair<long long int,int>>pq;
        dis[0]=0;
        paths[0]=1;
        pq.push({-0LL,0});
        while(!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            long long int d = -cur.first;
            int node = cur.second;
            // if(vis[node])continue;
            // vis[node]=1;
            if(d>1LL*dis[node])continue;
            for(auto v:g[node])
            {
                if(dis[v.first]>dis[node]+v.second)
                {
                    dis[v.first]=dis[node]+v.second;
                    paths[v.first]=paths[node]%mod;
                    pq.push({-dis[v.first],v.first});
                }
                else if(dis[v.first]==dis[node]+v.second)
                {
                    paths[v.first] = (paths[v.first]+paths[node])%mod;
                }
            }
        }
        return paths[n-1]%mod;
    }
};