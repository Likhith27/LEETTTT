class Solution {
public:
    int binpow(int x, unsigned int y,unsigned int mod)
    {
        if(y==0)
            return 1;
        long p = binpow(x,y/2,mod)%mod;
        p = (p*p)%mod;
        return y%2 ? (p*x)%mod : p;
    }
    vector<int> getGoodIndices(vector<vector<int>>& v, int target) {
        vector<int> res;
        for (int i = 0; i < v.size(); ++i)
            if (binpow(binpow(v[i][0], v[i][1], 10), v[i][2], v[i][3]) == target)
                res.push_back(i);
        return res;
    }
};