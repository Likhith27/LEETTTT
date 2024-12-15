class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>g(n+1);
        // g.resize(n+1);
        for(auto &it:times)
        {
            g[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dis(n+1,1e9);
        priority_queue<pair<int,int>>pq;
        
        pq.push({-0,k});
        dis[k]=0;
        while(!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            
            int d = -cur.first;
            int node = cur.second;

            for(auto v:g[node])
            {
                if(dis[v.first]>dis[node]+v.second)
                {
                    dis[v.first]=dis[node]+v.second;
                    pq.push({-dis[v.first],v.first});
                }
            }
        }
        int maxi = -1e9;
        for(int i=1;i<=n;i++){
            maxi = max(maxi,dis[i]);
        }
        if(maxi==1e9)return -1;
        else return maxi;
    }
};