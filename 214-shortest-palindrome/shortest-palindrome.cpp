class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string l = s + "#" + rev_s;
        int n = l.size();
        vector<int> lps(l.size(), 0);
        for (int i = 1; i < l.size(); i++) {
            int j = lps[i - 1];
            while (j > 0 && l[i] != l[j])
                j = lps[j - 1];
            lps[i] = (j += l[i] == l[j]);
        }
        
        return rev_s.substr(0, s.size() - lps[n-1]) + s;
    }
};