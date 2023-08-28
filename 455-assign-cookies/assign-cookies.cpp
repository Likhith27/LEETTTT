class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        // int n = g.size();
        // int m = s.size();
        // // sort(g.begin(),g.end());
        // // sort(s.begin(),s.end());
        // int cnt=0;
        // for(int i=0;i<min(n,m);i++)
        // {
        //     if(s[i]>=g[i])
        //         cnt++;
        // }
        // return cnt;
        sort(s.begin(), s.end());

        int count = 0;
        for (int i = 0; i < g.size(); i++)
        {
            auto x = lower_bound(s.begin(), s.end(), g[i]);
            if (x != s.end())
            {
                count++;
                s.erase(x);
            }
        }

        return count;
        
    }
};