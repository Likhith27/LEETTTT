class Solution {
public:
    long long maximumTotalSum(vector<int>& v) 
    {
        sort(v.rbegin(),v.rend());
        int mini = v[0];
        long long int sum=0;
        int n = v.size();
        for(int i=0;i<n;i++)
        {
            mini= min(mini,v[i]);
            if(mini<=0)return -1;
            sum+=mini;
            mini-=1;
        }
        return sum;
    }
};