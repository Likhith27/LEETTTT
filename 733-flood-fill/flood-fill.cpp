class Solution {
public:
    int n, m;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool is_valid(int row, int col) {
        return row >= 0 && row < n && col >= 0 && col < m;
    }

    vector<pair<int, int>> neighbor(pair<int, int> node, vector<vector<int>>& image, int initialColor) {
        vector<pair<int, int>> temp;
        for (int i = 0; i < 4; i++) {
            int newr = node.first + dx[i];
            int newc = node.second + dy[i];
            if (is_valid(newr, newc) && image[newr][newc] == initialColor)
                temp.push_back({newr, newc});
        }
        return temp;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size();
        m = image[0].size();
        
        int initialColor = image[sr][sc];
        if (initialColor == color) return image; // Avoid infinite loop if the color is the same

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;
            for (auto v : neighbor(cur, image, initialColor)) {
                if (image[v.first][v.second] == initialColor) {
                    image[v.first][v.second] = color;
                    q.push(v);
                }
            }
        }
        return image;
    }
};
