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
       vector<vector<int>>v;
       q.push(root);
       while(!q.empty())
       {
         int n = q.size();
         vector<int>t;
         for(int i=0;i<n;i++)
         {
            auto cur = q.front();
            q.pop();
            t.push_back(cur->val);
            if(cur->left!=NULL)q.push(cur->left);
            if(cur->right!=NULL)q.push(cur->right);
         }
         v.push_back(t);
       } 
       return (int)v.size();
    }
};