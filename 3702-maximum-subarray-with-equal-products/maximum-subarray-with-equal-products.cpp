class Solution {
public:
    int prod(vector<int>&nums){
        int n = nums.size();
        int ans = 1;
        for(int i=0;i<n;i++)ans=ans*1ll*nums[i];
        return ans;
    }
    int g(vector<int>&v){
        int n = v.size();
        int gcd=0;
        for(int i=0;i<n;i++)gcd=__gcd(gcd,v[i]);
        return gcd;
    }
    int f(vector<int>&v){
        int n = v.size();
        int ans = 1;
        for(int i=0;i<n;i++){
            ans = lcm(ans,v[i]);
        }
        return ans;
    }
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                vector<int>v;
                for(int k=i;k<=j;k++)
                    v.push_back(nums[k]);
                if(v.size()>0 and prod(v)==f(v)*g(v))
                {
                    maxi = max(maxi,(int)v.size());
                }
            }
            
        }
        return maxi;
    }
};