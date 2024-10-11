class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int> vis(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        vector<long long> v;
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);  // Accumulate the total sum of nums

        for (int i = 0; i < m; i++) {
            int a = queries[i][0];
            int b = queries[i][1];

            // Process the element `a` from the query
            if (!vis[a]) {
                sum -= nums[a];
                vis[a] = 1;
            }

            // Process the next `b` smallest unmarked elements from the priority queue
            int count = 0;
            while (count < b && !pq.empty()) {
                auto cur = pq.top();
                pq.pop();

                if (!vis[cur.second]) {
                    sum -= nums[cur.second];
                    vis[cur.second] = 1;
                    count++;  // Only increment count for unmarked elements
                }
            }

            v.push_back(sum);  // Store the current sum after the query is processed

            // Debugging print statement to check the state of `vis` array
            // for (int j = 0; j < n; j++) cout << vis[j] << " ";
            // cout << endl;
        }

        return v;
    }
};
