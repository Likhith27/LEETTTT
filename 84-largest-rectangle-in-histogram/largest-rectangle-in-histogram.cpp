class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        stack<int>st,st1;
        vector<int>pse(n,-1),nse(n,n);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and heights[st.top()]>=heights[i])
                st.pop();
            
            if(!st.empty())
                pse[i]=st.top();
            st.push(i);
        }   
        for(int i=n-1;i>=0;i--)
        {
            while(!st1.empty() and heights[st1.top()]>=heights[i])
                st1.pop();
            
            if(!st1.empty())
                nse[i]=st1.top();
            st1.push(i);
        }  
        int maxi = INT_MIN; 
        for(int i=0;i<n;i++)
        {
            maxi = max(maxi,(nse[i]-pse[i]-1)*heights[i]);
        }
        return maxi;
    }
};