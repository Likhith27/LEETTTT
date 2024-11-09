/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>v;
        if(root==NULL)return v;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int n = q.size();
            vector<int>t;
            for(int i=0;i<n;i++)
            {
                auto cur = q.front();
                q.pop();

                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
                t.push_back(cur->val);
            }
            v.push_back(t);
        }
        int cnt=0;
        for(auto &i:v)
        {
            cnt++;
            if(cnt%2==0)reverse(i.begin(),i.end());
        }
        return v;
    }
};