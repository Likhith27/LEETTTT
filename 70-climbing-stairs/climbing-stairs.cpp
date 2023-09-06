class Solution {
public:
// int f(int ind)
// {
//     if(ind==0)
//         return 1;
//     int left = f(ind-1);
//     int right = f(ind-2);
//     return left+right;
// }
    int climbStairs(int n) {
        int prev1=1;
        int prev2 =1;
        for(int i=2;i<=n;i++)
        {
            int cur = prev1 + prev2;
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};