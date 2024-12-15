class Solution {
public:
    const int mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>g;
        g.resize(n);
        for(auto &it:roads){
            int a = it[0];
            int b = it[1];
            int c = it[2];
            g[a].push_back({b,c});
            g[b].push_back({a,c});
        }   
        vector<long long int>dis(n,1e18);
        vector<long long int>cnt(n,1);
        vector<int>vis(n,0);
        priority_queue<pair<long long int,int>>pq;
        pq.push({-0ll,0});
        dis[0]=0;
        cnt[0]=1;
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();

            long long int d = -cur.first;
            int node = cur.second;
            if(vis[node])continue;
            vis[node]=1;
            if(d>1ll*dis[node])continue;
            for(auto v:g[node]){
                if(dis[v.first]>dis[node]+v.second){
                    dis[v.first]=dis[node]+v.second;
                    cnt[v.first]=cnt[node];
                    pq.push({-dis[v.first],v.first});
                }
                else if(dis[v.first]==dis[node]+v.second){
                    cnt[v.first]=(cnt[v.first]+cnt[node])%mod;
                    cnt[v.first]%=mod;
                }
            }
        }
        return cnt[n-1]%mod;
    }
};