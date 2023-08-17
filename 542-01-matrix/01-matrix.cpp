class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>vis(m,vector<int>(n,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    vis[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        while(!q.empty())
        {
            auto k = q.front();
            q.pop();
            int row = k.first;
            int col = k.second;

            for(int i=0;i<4;i++)
            {
                int newr = row+dr[i];
                int newc = col+dc[i];
                if(newr>=0 && newr<m && newc>=0 && newc<n)
                {
                    if(vis[newr][newc]>1+vis[row][col])
                    {
                        vis[newr][newc] = 1+vis[row][col];
                        q.push({newr,newc});
                    }
                }
            }
        }
        return vis;


    }
};