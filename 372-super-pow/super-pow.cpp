class Solution {
public:
    int f(int a,int b,int m)
    {
        int ans =1;
        a = a%m;
        while(b>0)
        {
            if(b&1)
            {
                ans = (a*ans)%m;
            }
            a = (a*a)%m;
            b>>=1;
        }
        return ans;
    }
    int superPow(int a, vector<int>& b) {
        int k=0;
        int n = b.size();
        for(int i=0;i<n;i++)
        {
            k = (k*10+b[i])%1140;
        }
        return f(a,k,1337);
    }
};