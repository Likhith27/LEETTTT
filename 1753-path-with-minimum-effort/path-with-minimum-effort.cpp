class Solution {
public:
    int n, m;
    vector<vector<int>> dist;
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    bool is_valid(int row, int col) {
        return row >= 0 && row < n && col >= 0 && col < m;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        // Initialize distance matrix
        dist.assign(n, vector<int>(m, 1e9));
        dist[0][0] = 0;

        // Priority queue to store {effort, {row, col}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int effort = it.first;
            int row = it.second.first;
            int col = it.second.second;

            // If we have reached the destination cell, return the effort
            if (row == n - 1 && col == m - 1) return effort;

            for (int i = 0; i < 4; i++) {
                int newr = row + dr[i];
                int newc = col + dc[i];

                if (is_valid(newr, newc)) {
                    int newEffort = max(abs(heights[row][col] - heights[newr][newc]), effort);

                    if (newEffort < dist[newr][newc]) {
                        dist[newr][newc] = newEffort;
                        pq.push({newEffort, {newr, newc}});
                    }
                }
            }
        }
        return 0; // If unreachable
    }
};