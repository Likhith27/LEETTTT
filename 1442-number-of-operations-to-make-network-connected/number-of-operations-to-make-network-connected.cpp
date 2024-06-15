class Solution {
public:
    vector<int>par,siz;
    int find(int x)
    {
        if(par[x]==x)return x;
        return par[x]=find(par[x]);
    }
    void merge(int x,int y)
    {
        int xroot = find(x);
        int yroot = find(y);
        if(xroot!=yroot)
        {
            if(siz[xroot]>=siz[yroot])
            {
                par[yroot]=xroot;
                siz[xroot]+=siz[yroot];
            }
            else
            {
                par[xroot]=yroot;
                siz[yroot]+=siz[xroot];
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        int cntextra=0;
        par.assign(n,0);
        siz.assign(n,1);
        for(int i=0;i<n;i++)par[i]=i;
        for(auto i:connections)
        {
            int a = i[0];
            int b = i[1];
            if(find(a)==find(b))
                cntextra++;
            else
                merge(a,b);
        }
        int cnt=0;//number of connected components
        for(int i=0;i<n;i++)
        {
            if(par[i]==i)
                cnt++;
        }
        int ans = cnt-1; //components-1 required to make the graph fully connected
        if(cntextra>=ans)
            return ans;
        return -1;
    }
};