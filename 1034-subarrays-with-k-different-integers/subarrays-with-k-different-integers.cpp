class Solution {
public:
    int freq[100100];
    int f(vector<int>& nums, int k)
    {
        int n=nums.size();
        int head=-1;
        int tail=0;
        int cnt=0;
        int ans=0;

        while(tail<n)
        {
            while(head+1<n and (cnt<k||freq[nums[head+1]]>0))
            {
                head++;
                if(freq[nums[head]]==0)
                    cnt++;
                freq[nums[head]]++;
            }
            ans+= (head-tail+1);
            if(head>=tail)
            {
                freq[nums[tail]]--;
                if(freq[nums[tail]]==0)
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
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums,k)-f(nums,k-1);
    }
};