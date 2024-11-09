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
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;
        queue<TreeNode*>q;
        q.push(root);
        vector<int>v;
        while(!q.empty())
        {
            int n = q.size();
            int cnt=0;
            for(int i=0;i<n;i++)
            {
                auto cur = q.front();
                q.pop();

                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
                cnt++;
            }
            v.push_back(cnt);
        }
        return v.size();
    }
};