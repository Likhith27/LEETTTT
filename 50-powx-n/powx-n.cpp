class Solution {
public:
    double myPow(double x, int n) {
         double res = 1;
        long long m = n;
        if(n<0)
            m = -1*m;
        while(m)
        {
            if(m&1)  
            {
                res = res*x;
                m -= 1;
            }
            else if(m%2==0)
            {
                x = x*x;
                m /= 2;
            }
        }
        if(n<0) res = (double)(1.0)/(double)(res);
        return res;
    }
};