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
    void dfs(TreeNode* node, forward_list<int> & leafs) {
        if (!node) return;
        
        if (!node->left && !node->right) {
            leafs.push_front(node->val);    
            return;
        }
        
        dfs(node->left, leafs);
        dfs(node->right, leafs);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        forward_list<int> leafs1, leafs2;
        dfs(root1, leafs1);
        dfs(root2, leafs2);
        return leafs1 == leafs2;
    }
};