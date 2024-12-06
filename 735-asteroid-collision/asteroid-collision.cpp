class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int>st;
        //push all the positive things into stack
        int n = arr.size();
        for(int i=0;i<n;i++){
            //push all the positive things into stack
            if(st.empty()||arr[i]>0)st.push(arr[i]);
            else
            {
                //we now have negatives in the array we compare with values
                //in the stack 
                while(!st.empty() and st.top()>0 and st.top()<abs(arr[i]))
                    st.pop();
                if(!st.empty() and st.top()==abs(arr[i]))st.pop();
                else
                {
                    if(st.empty()||st.top()<0)
                        st.push(arr[i]);
                }
            }
        }
        vector<int>v;
            while(!st.empty()){
                v.push_back(st.top());
                st.pop();
            }
            reverse(v.begin(),v.end());
            return v;
    }
};