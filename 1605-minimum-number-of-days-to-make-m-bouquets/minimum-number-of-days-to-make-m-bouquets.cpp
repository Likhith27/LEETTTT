class Solution {
public:
    int check(int days,int m,int k,vector<int>&bloomDay)
    {
        int n = bloomDay.size();
        int ans=0;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(bloomDay[i]<=days)
                cnt++;
            else
            {
                ans += (cnt/k);
                cnt=0;
            }
        }
        ans += (cnt/k);
        return ans>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(check(mid,m,k,bloomDay))
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