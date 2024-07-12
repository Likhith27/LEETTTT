class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>nge(n),pge(n);
        pge[0]=height[0];
        nge[n-1]=height[n-1];
        for(int i=1;i<n;i++)
        {
            pge[i] = max(pge[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--)
            nge[i] = max(nge[i+1],height[i]);
        
        int res=0;
        for(int i=1;i<=n-2;i++)
        {
            int ans = min(pge[i-1],nge[i+1]);
            if(ans > height[i])
                res += ans-height[i];
        }
        return res;

    }
};