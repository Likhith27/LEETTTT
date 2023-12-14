class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        // Code
        int m = grid.size();
        int n = grid[0].size();

        vector<int> row0;
        vector<int> row1;
        vector<int> col0;
        vector<int> col1;

        for(int i = 0; i < m; i++)
        {
            int zero = 0;
            int one = 0;
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 0) zero++;
                else one++;
            }
            row0.push_back(zero);
            row1.push_back(one);
        }

        for(int i = 0; i < n; i++)
        {
            int zero = 0;
            int one = 0;
            for(int j = 0; j < m; j++)
            {
                if(grid[j][i] == 0) zero++;
                else one++;
            }
            col0.push_back(zero);
            col1.push_back(one);
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                grid[i][j] = row1[i] + col1[j] - row0[i] - col0[j];
            }
        }

        return grid;
    }
};