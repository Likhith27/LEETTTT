class Solution {
public:
    vector<int> topo, vis;

    bool dfs(int node, vector<vector<int>>& g) {
        vis[node] = 1; // Mark the node as visiting
        for (auto v : g[node]) {
            if (vis[v] == 0) {
                if (!dfs(v, g)) return false; // If a cycle is detected, return false
            } else if (vis[v] == 1) {
                return false; // A cycle is detected
            }
        }
        vis[node] = 2; // Mark the node as visited
        topo.push_back(node); // Add to the topological sort
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vis.assign(numCourses, 0); // Initialize visitation status
        vector<vector<int>> g(numCourses);
        for (const auto& pre : prerequisites) {
            g[pre[1]].push_back(pre[0]); // Directed edge from prerequisite to course
        }

        for (int i = 0; i < numCourses; ++i) 
        {
            if (!vis[i]) 
            {
                if (!dfs(i, g)) 
                    return {}; // If a cycle is detected, return an empty vector
            }
        }

        reverse(topo.begin(), topo.end());
        return topo;
    }
};
