class Solution {
public:
    int dx[8]={-1,-1,0,1,1,1,0,-1};
    int dy[8]={0,1,1,1,0,-1,-1,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1)return -1;

        queue<pair<int,int>>q;
        q.push({0,0});
        vector<vector<int>>dis;
        dis.assign(n,vector<int>(m,1e9));
        dis[0][0]=1;

        while(!q.empty()){
            auto cur= q.front();
            q.pop();

            int x = cur.first;
            int y = cur.second;
            for(int i=0;i<8;i++){
                int newr = x+dx[i];
                int newc = y+dy[i];
                if(newr>=0 and newr<n and newc>=0 and newc<m and dis[newr][newc]==1e9 and grid[newr][newc]==0){
                    dis[newr][newc] = dis[x][y]+1;
                    q.push({newr,newc});
                }
            }
        }
        if(dis[n-1][m-1]!=1e9)
            return dis[n-1][m-1];
        else return -1;
    }
};