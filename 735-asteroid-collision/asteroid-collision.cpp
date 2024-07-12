class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        stack<int>st;
        //8, 9, 6, -7, -9, 12, 50, -34
        for(int i=0;i<n;i++)
        {
            //stack empty or positive
            if(st.empty()||arr[i]>0)
                st.push(arr[i]);
            
            else 
            {
                while(!st.empty() and st.top()>0 and st.top()<abs(arr[i]))
                    st.pop(); //st.top() is positive
                
                if(!st.empty() and st.top()==abs(arr[i]))
                    st.pop();
                else
                {
                    if(st.empty() || st.top()<0)
                        st.push(arr[i]);
                }
                
            }
        }
        vector<int>v;
        while(!st.empty())
        {
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};