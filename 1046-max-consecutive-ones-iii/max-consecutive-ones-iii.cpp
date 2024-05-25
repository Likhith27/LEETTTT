class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int head = -1;
        int tail = 0;
        int cnt=0,ans=0;
        while(tail<n)
        {
            while(head+1<n and ((nums[head+1]==1 and cnt<=k)||nums[head+1]==0 and cnt<k))
            {
                head++;
                if(nums[head]==0)
                  cnt++;
            }
            //record the size
            ans = max(ans,head-tail+1);

            if(head>=tail)
            {
                if(nums[tail]==0)
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
};