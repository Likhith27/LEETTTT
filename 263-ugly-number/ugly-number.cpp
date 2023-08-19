class Solution {
public:
    bool isUgly(int n) {
        // if(n==1)
        //     return true;
        // vector<int>v(n);
        // for(int i=1;i*i<=n;i++)
        // {
        //     if(n%i==0)
        //         v.push_back(n/i);
        // }
        // int flag=0;
        // for(int i=0;i<n;i++)
        // {
        //     if(v[i]==2 || v[i]==3||v[i]==5)
        //         flag=1;
        // }
        // return flag==1;
        if (n <= 0) return false;
        while(n > 1)
        {
            if (n % 2 == 0) n = n / 2;
            else if (n % 3 == 0) n = n / 3;
            else if (n % 5 == 0) n = n / 5;
            else break;
        }
        return n==1;
    }
};