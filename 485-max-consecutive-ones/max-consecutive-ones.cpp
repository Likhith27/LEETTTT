class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int head =-1;
        int tail=0;
        int maxi = 0;
        int cnt=0;
        while(tail<n){
            while(head+1<n and nums[head+1]==1){
                head++;
                cnt++;
            }
            maxi = max(maxi,head-tail+1);
            // maxi = max(maxi,cnt);
            if(head>=tail){
                cnt--;
                tail++;
            }
            else
            {
                tail++;
                head = tail-1;
            }
        }
        return maxi;
    }
};