class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;

        while (!nums.empty()) {
            // Check if the current array is distinct
            unordered_set<int> uniqueElements(nums.begin(), nums.end());
            if (uniqueElements.size() == nums.size()) {
                break; // All elements are distinct
            }

            // Perform the operation: remove the first 3 elements
            nums.erase(nums.begin(), nums.begin() + min(3, (int)nums.size()));
            operations++;
        }

        return operations;
    }
};