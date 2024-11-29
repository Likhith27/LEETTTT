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
        vector<int>last_end = intervals[0];
        // int n = intervals.size();
        for(int i=1;i<n;i++)
        {
            //case-I if(next intervals start is less than or equal to first interval end)
            if(intervals[i][0]<=last_end[1])
            {
                last_end[1]=max(last_end[1],intervals[i][1]);
            }
            //case-2(if they don't overlap then directly add to the range list)
            else
            {
                v.push_back(last_end);
                last_end = intervals[i];
            }
        }
        v.push_back(last_end);
        return v;

    }
};