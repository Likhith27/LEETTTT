class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        map<char, int> mp;

        int tail = 0;
        int head = -1;
        int ans = 0;

        while (tail < n) {
            while (head + 1 < n && (mp['a'] == 0 || mp['b'] == 0 || mp['c'] == 0)) {
                head++;
                mp[s[head]]++;
            }
            if (mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0)
                ans += n - head;
            mp[s[tail]]--;
            tail++;
        }
        
        return ans;
    }
};