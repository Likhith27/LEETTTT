class Solution {
public:
    int f(vector<int>& nums, int k)
    {
        int n=nums.size();
        int head=-1;
        int tail=0;
        int ans=0;
        int cnt=0;
        while(tail<n)
        {
            while(head+1<n and ((nums[head+1]==1 and cnt<=k)||(nums[head+1]==0 and cnt<k)))
            {
                head++;
                if(nums[head]==0)
                    cnt++;
            }
            ans += (head-tail+1);
            if(head>=tail)
            {
                if(nums[head]=0)
                    cnt--;
                tail++;
            }
            else
            {
                tail++;
                head=tail-1;
            }
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>arr(n);
        for(int i=0;i<n;i++)
            arr[i] = (nums[i]%2!=0);
        
        map<int,int>mp;
        mp[0]++;
        int psum=0,ans=0;
        for(auto i:arr)
        {
            psum+=i;
            ans += mp[psum-k];
            mp[psum]++;
        }
        return ans;
        
    }
};