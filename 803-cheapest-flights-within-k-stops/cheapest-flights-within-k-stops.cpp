class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // pq state : {cost, {node, tickets}}
        //state:{node,tickets}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<int>> dis(n, vector<int>(k + 2, INT_MAX));
        vector<vector<pair<int, int>>> g(n);
        
        for (auto edge : flights) 
        {
            g[edge[0]].push_back({edge[1], edge[2]});
        }
        
        dis[src][0] = 0;
        pq.push({0, {src, 0}});
        
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            
            int cost = cur.first;
            int nn = cur.second.first;
            int stops = cur.second.second;
            
            if (stops > k) continue;

            for (auto v : g[nn]) {
                int nextNode = v.first;
                int edgeWeight = v.second;
                
                if (cost + edgeWeight < dis[nextNode][stops + 1]) {
                    dis[nextNode][stops + 1] = cost + edgeWeight;
                    pq.push({cost + edgeWeight, {nextNode, stops + 1}});
                }
            }
        }
        
        int ans = INT_MAX;
        for (int i = 0; i <= k + 1; ++i) {
            ans = min(ans, dis[dst][i]);
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};
