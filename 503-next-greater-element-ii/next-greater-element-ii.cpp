class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>v;
        int n = nums.size();
        for(int i=0;i<n;i++)v.push_back(nums[i]);
        for(int i=0;i<n;i++)v.push_back(nums[i]);

        //nge
        stack<int>st;
        vector<int>nge(2*n,-1);
        for(int i=2*n-1;i>=0;i--)
        {
            while(!st.empty() and st.top()<=v[i])
                st.pop();

            if(!st.empty())
                nge[i] = st.top();
            
            st.push(v[i]);
        }
        vector<int>t(n,0);
        for(int i=0;i<n;i++)t[i]=nge[i];
        return t;

    }
};