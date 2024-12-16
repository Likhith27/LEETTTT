class Solution {
public:
    int n, m;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool is_valid(int row, int col) {
        return row >= 0 && row < n && col >= 0 && col < m;
    }

    void dfs(int row, int col, vector<vector<int>>& grid) {
        if (!is_valid(row, col) || grid[row][col] != 1) return;
        grid[row][col] = 2;  
        for (int i = 0; i < 4; i++) 
        {
            int newr = row + dx[i];
            int newc = col + dy[i];
            dfs(newr, newc, grid);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        // Mark all '1's connected to the borders
        for (int i = 0; i < n; i++) {
            dfs(i, 0, grid);
            dfs(i, m - 1, grid);
        }
        for (int i = 0; i < m; i++) {
            dfs(0, i, grid);
            dfs(n - 1, i, grid);
        }

        // Count the remaining '1's that are enclaves
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};