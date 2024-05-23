class Solution {
public:
    int check(int ind,int h,vector<int>&piles)
    {
        long long int ans=0;
        for(int i=0;i<piles.size();i++)
            ans += (piles[i]+ind-1)/ind;

        return ans <=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int ans=-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(check(mid,h,piles))
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};