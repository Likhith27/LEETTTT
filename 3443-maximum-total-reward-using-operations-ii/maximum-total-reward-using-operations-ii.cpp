class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(),rewardValues.end());
        bitset<100100>g;
        bitset<100100>mask;
        g[0]=1;
        int cur =0;
        for(auto x:rewardValues)
        {
            while(cur<x)
              mask.set(cur++);
            g |= (g&mask)<<x;
        }
        int ind= g.size()-1;
        while(g[ind]==0)
            ind--;
        return ind;
    }
};