class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>>v;
        if(n==0)
        {
            return v;
        }
        sort(intervals.begin(),intervals.end());
        vector<int>temp = intervals[0];

        for(auto range:intervals)
        {
            //case-I if(next intervals start is less than or equal to first interval end)
            if(range[0]<=temp[1])
            {
                temp[1]=max(temp[1],range[1]);
            }
            //case-2(if they don't overlap then directly add to the range list)
            else
            {
                v.push_back(temp);
                temp = range;
            }
        }
        v.push_back(temp);
        return v;

    }
};