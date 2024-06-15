class Solution {
public:
    vector<int>vis;
    vector<int> safeNodes;

    bool dfs(int node, vector<vector<int>>& graph, vector<int>& color) {
        // if (color[node] != 0) 
        // {
        //     return color[node] == 2;
        // }
        
        color[node] = 1; // Mark the node as being processed

        for (auto v : graph[node]) {
            if (color[v] == 2) {
                continue;
            }
            if (color[v] == 1 || !dfs(v, graph, color)) {
                return false;
            }
        }
        
        color[node] = 2; // Mark the node as safe
        safeNodes.push_back(node);
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0); // 0 = unvisited, 1 = visiting, 2 = safe
        
        for (int i = 0; i < n; ++i) {
            if (color[i] == 0) {
                dfs(i, graph, color);
            }
        }
        
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
