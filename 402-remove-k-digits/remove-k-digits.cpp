class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() > num[i] && k > 0) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        // If k is still greater than 0, remove the remaining digits from the end
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Construct the result from the stack
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        // Reverse the result to get the correct order
        reverse(ans.begin(), ans.end());

        // Remove leading zeros
        int i = 0;
        while (i < ans.size() && ans[i] == '0') {
            i++;
        }

        // If the result is empty after removing leading zeros, return "0"
        if (i == ans.size()) {
            return "0";
        }

        return ans.substr(i);
    }
};
