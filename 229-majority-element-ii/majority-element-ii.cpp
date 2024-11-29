class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n= nums.size();
        int cnt1=0,cnt2=0;
        int ele1,ele2;
        for(int i=0;i<n;i++){
            if(cnt1==0 and nums[i]!=ele2){
                cnt1=1;
                ele1 = nums[i];
            }
            else if(cnt2==0 and nums[i]!=ele1){
                cnt2=1;
                ele2 = nums[i];
            }
            else if(ele1==nums[i])cnt1++;
            else if(ele2==nums[i])cnt2++;
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        vector<int>v;
        cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(ele1==nums[i])cnt1++;
            if(ele2==nums[i])cnt2++;
        }
        int mini = (n/3)+1;
        if(cnt1>=mini)v.push_back(ele1);
        if(cnt2>=mini and ele2!=ele1)v.push_back(ele2);
        sort(v.begin(),v.end());
        return v;
    }
};