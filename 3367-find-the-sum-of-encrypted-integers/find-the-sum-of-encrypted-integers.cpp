class Solution {
public:
    int f(int n)
    {
        vector<int>v;
        while(n!=0)
        {
            v.push_back(n%10);
            n=n/10;
        }
        int k = *max_element(v.begin(),v.end());
        int m = v.size();
        // string str="";
        // for(int i=0;i<m;i++)str+=(char)k;
        int ans = 0;
        for(int i=0;i<m;i++)
        {
            ans += k;
            ans *=10;
        }
        return ans/10;
    }
    int sumOfEncryptedInt(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        for(int i=0;i<n;i++)
        {
            int k = nums[i];
            ans += f(nums[i]);
        }
        return ans;
    }
};