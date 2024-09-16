class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //2,3,-2,4
        //-1 2 3 0 -1 max = 6 
        //-1 -2 -6 6 
        //-2,0,-1
        // -2, 0 ,-1
        //0,2,-1 // 1
        int n = nums.size();
        int prod=1;
        int maxi =-1e9;
        for(int i=0;i<n;i++)
        {
            prod=1LL*prod*nums[i];
            maxi = max(maxi,prod);
            if(prod==0)prod=1;
        }
        prod =1;
        for(int i=n-1;i>=0;i--)
        {
            prod=1LL*prod*nums[i];
            maxi = max(maxi,prod);
            if(prod==0)prod=1;
        }
        return maxi;
    }
};