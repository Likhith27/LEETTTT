class Solution {
    vector<int> par, siz;

    int findPar(int x) {
        if (par[x] == x) return x;  // Fixed the recursive condition
        return par[x] = findPar(par[x]);  // Path compression
    }

    void merge(int x, int y) {
        int find_x = findPar(x);
        int find_y = findPar(y);
        if (find_x == find_y) return;  // Already in the same group

        if (siz[find_x] > siz[find_y]) {
            siz[find_x] += siz[find_y];
            par[find_y] = find_x;
        } else {
            siz[find_y] += siz[find_x];
            par[find_x] = find_y;
        }
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& details) {
        int n = details.size();
        siz.assign(n, 1);
        par.assign(n, 0);
        for (int i = 0; i < n; i++) par[i] = i;

        unordered_map<string, int> mapMailNode;

        // Merging accounts based on common email
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < details[i].size(); j++) {
                string mail = details[i][j];
                if (mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                } else {
                    merge(i, mapMailNode[mail]);
                }
            }
        }

        vector<string> mergedMail[n];

        // Collect emails for each account's representative
        for (auto& it : mapMailNode) {
            string mail = it.first;
            int node = findPar(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;

        // Preparing the final merged accounts
        for (int i = 0; i < n; i++) {
            if (mergedMail[i].empty()) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(details[i][0]);  // Account name
            for (auto& it : mergedMail[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
