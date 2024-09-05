class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](vector<int>& a, vector<int>& b) 
        {
            return a[1] < b[1];
        });
        int last_end = intervals[0][1];
        int cnt=0;
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]<last_end)
                cnt++;
            else
                last_end=intervals[i][1];
        }
        return cnt;
    }
};