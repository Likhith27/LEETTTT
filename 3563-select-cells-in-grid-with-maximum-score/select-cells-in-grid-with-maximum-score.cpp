class Solution {
public:
    int dp[105][1030];
    int solve(int ind,int mask,map<int,vector<int> >&arr){
        if(ind==0){
            return 0;
        }
        if(dp[ind][mask] != -1){
            return dp[ind][mask];
        }
        
        int res=solve(ind-1,mask,arr);
        
        for(auto i:arr[ind]){
            if((mask & (1<<i))==0){
                res=max(res,ind+solve(ind-1,mask|(1<<i),arr));
            }
        }
        
        return dp[ind][mask]=res;
    }
    int maxScore(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        map<int,vector<int> > arr;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[grid[i][j]].push_back(i);
            }
        }
        
        return solve(100,0,arr);
    }
};