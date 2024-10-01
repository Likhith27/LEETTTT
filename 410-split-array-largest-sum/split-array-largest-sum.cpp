class Solution {
public:
    int check(int x,int k,vector<int>&arr)
    {
        int n = arr.size();
        int no_of_painters=0;
        int last_sum=0;
        for(int i=0;i<n;i++)
        {
            if(last_sum>=arr[i])
            {
                last_sum-=arr[i];
            }
            else
            {
                no_of_painters++;
                last_sum=x;
                if(last_sum>=arr[i])
                {
                    last_sum-=arr[i];
                }
                else
                    return 0;
            }
        }
        return no_of_painters<=k;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid, k, nums)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
