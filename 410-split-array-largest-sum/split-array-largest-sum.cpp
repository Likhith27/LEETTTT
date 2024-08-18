class Solution {
public:
    bool check(int x, int k, vector<int>& arr) {
        int students = 1;  // Start with 1 subarray
        int sum = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (sum + arr[i] > x) {
                students++;  // Start a new subarray
                sum = arr[i];
         // Early exit if we exceed k subarrays
            } else {
                sum += arr[i];
            }
        }
        return students<=k;  // Return true if students <= k
    }
    
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid, k, nums)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
