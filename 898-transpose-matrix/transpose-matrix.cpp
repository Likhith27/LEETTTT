class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) 
    {
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> v;
        for(int i=0;i<m;i++)
        {
            vector<int> k;
            for(int j=0;j<n;j++)
            {
                k.push_back(matrix[j][i]);
            }
            v.push_back(k);
        }
        return v;
    }
};