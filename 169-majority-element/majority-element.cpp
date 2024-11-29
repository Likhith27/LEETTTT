class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ele=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(cnt==0){
                cnt=1;
                ele = nums[i];
            }
            else if(ele==nums[i])cnt++;
            else cnt--;
        }
        // int cnt1=0;
        // for(int i=0;i<n;i++){
        //     if(ele==nums[i])cnt1++;
        // }
        return ele;      
    }
};