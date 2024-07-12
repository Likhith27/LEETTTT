class Solution {
public:
    const int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int>nse(n,n),pse(n,-1);
        stack<int>st,st1;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and arr[st.top()]>=arr[i])
                st.pop();
            if(!st.empty())
                pse[i] = st.top();
            st.push(i);
        }
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st1.empty() and arr[st1.top()]>arr[i])
                st1.pop();
            if(!st1.empty())
                nse[i] = st1.top();
            st1.push(i);
        }
        long long int ans=0;
        for(int i=0;i<n;i++)
        {
            long long int k = 1LL*(nse[i]-i)*(i-pse[i])%mod;
            ans += (1LL*k*arr[i])%mod;

        }
        return ((ans%mod)+mod)%mod;

    }
};