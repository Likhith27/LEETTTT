class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int>nge(n,-1);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and nums2[st.top()]<=nums2[i]){
                st.pop();
            }
            if(st.empty())nge[i]=-1;
            else nge[i]=st.top();
            st.push(i);
        }
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums2[i]] = nge[i] == -1 ? -1 : nums2[nge[i]];
        }
        vector<int>v;
        for(int i=0;i<nums1.size();i++){
            v.push_back(mp[nums1[i]]);
        }
        return v;
    }
};