class Solution {
public:
    int check(int x,int k,int m,vector<int>&bloomday){
        int n = bloomday.size();
        int cnt=0,ans=0;
        for(int i=0;i<n;i++){
            if(bloomday[i]<=x)
            {
                cnt++;
            }
            else{
                ans += cnt/k;
                cnt=0;
            }
        }
        ans+=cnt/k;
        return ans>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high =*max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(check(mid,k,m,bloomDay)){
                ans = mid;
                high= mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }
};