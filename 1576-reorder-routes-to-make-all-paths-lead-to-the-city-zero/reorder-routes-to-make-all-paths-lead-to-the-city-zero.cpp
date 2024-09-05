class Solution {
public:
    vector<vector<pair<int,int>>>g;
    vector<int>vis;
    // void bfs01(int node)
    // {
    //     dis[node]=0;
    //     deque<pair<int,int>>dq;
    //     dq.push_front(node);
    //     while(!dq.empty())
    //     {
    //         auto cur = dq.front();
    //         dq.pop_front();

    //         int node = cur.first;
    //         int wt = cur.second;
    //         for(auto v:g[node])
    //         {
    //             if(dis[v.first]>dis[node]+v.second)
    //             {
    //                 dis[v.first] = dis[node]+v.second;
    //                 if(wt==0)
    //                     dq.push_front({dis[v.first],v.first});
    //                 else
    //                     dq.push_back({dis[v.first],v.first});
    //             }
    //         }
    //     }
    // }
    int cnt=0;
    void dfs(int node)
    {
        vis[node]=1;
        for(auto v:g[node])
        {
            if(!vis[v.first])
            {
                cnt+=v.second;
                dfs(v.first);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        g.resize(n);
        vis.assign(n,0);
        for(auto &i:connections)
        {
            g[i[0]].push_back({i[1],0});
            g[i[1]].push_back({i[0],1});
        }
        dfs(0);
        return n-1-cnt;
    }
};