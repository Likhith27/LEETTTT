class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dis;
        queue<pair<int,int>>q;
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    grid[i][j]=0;
                    q.push({i,j});
                }
                else if(grid[i][j]==1)
                    count++;
            }
        }
        if(count==0)
            return 0;
        int time=-1;
        while(!q.empty()){
            int s=q.size();
            time++;
            for(int p=0;p<s;p++)
            {
                auto t = q.front();
                q.pop();
                int cx = t.first,cy = t.second;
                for(int i=0;i<4;i++)
                {
                    int nx=cx+dx[i];
                    int ny=cy+dy[i];
                    if(nx>=0 && ny>=0 &&nx<grid.size()&&ny<grid[0].size()&& grid[cx+dx[i]][cy+dy[i]]==1)
                    {
                        grid[cx+dx[i]][cy+dy[i]]=0;
                        count--;
                        q.push({cx+dx[i],cy+dy[i]});
                    }
                }
            }
            
        }
        if(count!=0)    
            return -1;
        return time;
    }
};