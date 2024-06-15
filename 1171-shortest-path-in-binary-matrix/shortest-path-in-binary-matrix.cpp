class Solution {
public:
    int n,m;
    vector<vector<int>>dis;
    int dx[8]={-1,-1,0,1,1,1,0,-1};
    int dy[8]={0,1,1,1,0,-1,-1,-1};
    bool is_valid(int row,int col,vector<vector<int>>&grid)
    {
        return row>=0 and row<n and col>=0 and col<m and grid[row][col]==0;
    }
    vector<pair<int,int>>neigh(pair<int,int>node,vector<vector<int>>&grid)
    {
        vector<pair<int,int>>temp;
        for(int i=0;i<8;i++)
        {
            int newr = node.first+dx[i];
            int  newc = node.second+dy[i];
            if(is_valid(newr,newc,grid))
                temp.push_back({newr,newc});
        }
        return temp;
    }
    void bfs(int row,int col,vector<vector<int>>&grid)
    {   
        
        queue<pair<int,int>>q;
        q.push({row,col});
        dis[row][col]=1;
        while(!q.empty())
        {
            auto cur = q.front();
            int x = cur.first;
            int y = cur.second;
            q.pop();
            // if(vis[x][y])continue;
            // vis[x][y]=1;
            for(auto v:neigh(cur,grid))
            {
                if(dis[v.first][v.second]>dis[x][y]+1)
                {
                    dis[v.first][v.second]=dis[x][y]+1;
                    q.push(v);
                }
            }
        }
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n= grid.size();
        m = grid[0].size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
            return -1;
        dis.assign(n,vector<int>(m,1e9));
        bfs(0,0,grid);
        // if(dis[n-1][n-1]==1e9)return -1;
        // else return dis[n-1][n-1];
        return dis[n-1][n-1] == 1e9 ? -1 : dis[n-1][n-1];
    }
};