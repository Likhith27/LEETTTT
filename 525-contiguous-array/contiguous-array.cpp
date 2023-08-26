class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n =  nums.size();
        map<int,int>mp;
        int prefixsum=0,ans=0;
        mp[0]=-1;//{sum,index}
        for(int i=0;i<n;i++)
        {
            if(nums[i])
                prefixsum+=1;
            else
                prefixsum-=1;
            if(mp.find(prefixsum)==mp.end())
            {
                mp[prefixsum]=i;
            }
            else
                ans = max(ans,i-mp[prefixsum]);
        }
        return ans;
        
    }
};