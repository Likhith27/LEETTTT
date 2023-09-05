class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int maxi =0;
        while(left<=right)
        {
            int ans = (right-left)*min(height[left],height[right]);
            maxi =  max(ans,maxi);
            if(height[left]<height[right])
                left++;
            else if(height[left]>height[right])
                right--;
            else
                left++;
        }
        return maxi;
    }
};