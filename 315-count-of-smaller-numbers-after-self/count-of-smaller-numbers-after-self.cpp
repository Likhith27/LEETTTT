#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Define the PBDS ordered set with pairs
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        ordered_set os; // PBDS ordered set

        // Iterate from the end of the array to the beginning
        for (int i = n - 1; i >= 0; --i) {
            // Find the number of elements smaller than nums[i]
            result[i] = os.order_of_key({nums[i], i});
            // Insert the current element into the ordered set with index
            os.insert({nums[i], i});
        }

        return result;
    }
};