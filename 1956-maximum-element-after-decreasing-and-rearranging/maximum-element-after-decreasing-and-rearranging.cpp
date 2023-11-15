class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int pre=0;
        for(int i=0;i<n;i++)
        {
            pre = min(pre+1,arr[i]);
        }
        return pre;
    }
};