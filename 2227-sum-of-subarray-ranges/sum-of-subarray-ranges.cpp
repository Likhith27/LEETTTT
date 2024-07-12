class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
       int n = arr.size();

        vector<int>nse(n,n),pse(n,-1),pge(n,-1),nge(n,n);
        stack<int>st,st1,st2,st3;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and arr[st.top()]>=arr[i])
                st.pop();
            if(!st.empty())
                pse[i] = st.top();
            st.push(i);
        }

        for(int i=0;i<n;i++)
        {
            while(!st2.empty() and arr[st2.top()]<=arr[i])
                st2.pop();
            if(!st2.empty())
                pge[i] = st2.top();
            st2.push(i);
        }
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st1.empty() and arr[st1.top()]>arr[i])
                st1.pop();
            if(!st1.empty())
                nse[i] = st1.top();
            st1.push(i);
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!st3.empty() and arr[st3.top()]<arr[i])
                st3.pop();
            if(!st3.empty())
                nge[i] = st3.top();
            st3.push(i);
        }

        long long int ans=0,m=0,k=0;
        for(int i=0;i<n;i++)
        {
            k += 1LL*(nse[i]-i)*(i-pse[i])*arr[i];
            m += 1LL*(nge[i]-i)*(i-pge[i])*arr[i];
        }
        ans = (m-k);
        return ans;
    }
};