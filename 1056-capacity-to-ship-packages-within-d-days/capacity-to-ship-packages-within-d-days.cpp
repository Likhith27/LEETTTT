class Solution {
public:
    int check(int weight,int days,vector<int>&weights)
    {
        int days_spawned=1;
        int last_weight=0;
        int n = weights.size();
        for(int i=0;i<n;i++)
        {
            if(last_weight+weights[i]>weight)
            {
                days_spawned+=1;
                last_weight = weights[i];
            }
            else
            {
                last_weight+=weights[i];
            }
        }
        return days_spawned<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans=-1;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(check(mid,days,weights))
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