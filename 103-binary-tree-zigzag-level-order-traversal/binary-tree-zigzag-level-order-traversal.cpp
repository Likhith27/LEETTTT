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
        int flag =0;
        while(!q.empty())
        {
            int n = q.size();
            vector<int>t(n);
           
            for(int i=0;i<n;i++)
            {
                auto cur = q.front();
                q.pop();
                if(!flag)t[i]=cur->val;
                else t[n-i-1]=cur->val;
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
            flag=!flag;
            v.push_back(t);
        }
        return v;
    }
};