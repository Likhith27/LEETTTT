class Solution {
public:
    int n,m;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    bool is_valid(int row,int col)
    {
        return row>=0 and row<n and col>=0 and col<m;
    }
    vector<pair<int,int>>neighbor(pair<int,int>node)
    {
        vector<pair<int,int>>temp;
        for(int i=0;i<4;i++)
        {
            int newr = node.first + dx[i];
            int newc = node.second + dy[i];
            if(is_valid(newr,newc))
                temp.push_back({newr,newc});
        }
        return temp;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();
        vector<vector<int>>dis;
        dis.assign(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
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

            for(auto v:neighbor(cur))
            {
                if(dis[v.first][v.second]==-1)
                {
                    dis[v.first][v.second]=dis[cur.first][cur.second]+1;
                    q.push(v);
                }
            }
        }
        return dis;
    }
};