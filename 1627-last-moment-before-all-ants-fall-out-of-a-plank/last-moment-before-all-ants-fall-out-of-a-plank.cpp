class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) 
    {
        int k =0;
        for(auto i:left)
        {
            k = max(k,i);
        }
        for(auto i:right)
        {
            k = max(k,n-i);
        }
        return k;
        
    }
};