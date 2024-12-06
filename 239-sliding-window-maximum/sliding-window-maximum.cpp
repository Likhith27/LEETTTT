class Solution {
public:
    struct monotone_deque{
        deque<int>dq;
        void push(int x)
        {
           while(!dq.empty() and dq.back()<x){
             dq.pop_back();
           }
           dq.push_back(x);
        }
        void pop(int x){
            if(dq.front()==x)
                dq.pop_front();
        }
        int get_maxi(){
            return dq.front();
        }
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = -1e9;
        monotone_deque mt;
        for(int i=0;i<k;i++){
            mt.push(nums[i]);
        }
        vector<int>v;
        maxi = mt.get_maxi();
        v.push_back(maxi);
        for(int i=0;i<n-k;i++){
            mt.push(nums[i+k]);
            mt.pop(nums[i]);
            v.push_back(mt.get_maxi());
        }
        return v;
    }
};