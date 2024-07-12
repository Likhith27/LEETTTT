class Solution {
public:
    struct deq
    {
        deque<int>dq;
    
        void insert(int x)
        {
            while(!dq.empty() and dq.back()<x)
                dq.pop_back();
            dq.push_back(x);
        }

        void remove(int x)
        {
            if(dq.front()==x)
                dq.pop_front();
        }

        int getMax()
        {
            return dq.front();
        }
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        int n = nums.size();
        deq dq;
        for(int i=0;i<k;i++)
        {
            dq.insert(nums[i]);
        }
        vector<int>v;
        v.push_back(dq.getMax());
        for(int i=0;i<n-k;i++)
        {
            dq.insert(nums[i+k]);
            dq.remove(nums[i]);
            v.push_back(dq.getMax());
        }
        return v;
    }
};