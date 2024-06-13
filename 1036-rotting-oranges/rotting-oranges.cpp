class Solution {
public:
    int n,m;
    vector<vector<int>>dis;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    bool is_valid(int row,int col)
    {
        if(row>=0 and row<n and col>=0 and col<m)return 1;
        else return 0;
    }
    vector<pair<int,int>>neighbor(pair<int,int>node,vector<vector<int>>& grid)
    {
        vector<pair<int,int>>temp;
        for(int i=0;i<4;i++)
        {
            int newr = node.first+dx[i];
            int newc = node.second + dy[i];
            if(is_valid(newr,newc) and grid[newr][newc]==1)
                temp.push_back({newr,newc});
        }
        return temp;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dis.assign(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    dis[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty())
        {
            auto cur = q.front();
            q.pop();
            for(auto v:neighbor(cur,grid))
            {
                if(grid[v.first][v.second]!=2)
                {
                    grid[v.first][v.second]=2;
                    dis[v.first][v.second]=dis[cur.first][cur.second]+1;
                    q.push(v);
                }
            }
        }
        int maxi = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                   return -1;
                }
                maxi = max(dis[i][j],maxi);
            }
        }
        return maxi;
    }
};