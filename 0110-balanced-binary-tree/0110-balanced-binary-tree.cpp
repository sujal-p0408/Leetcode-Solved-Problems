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
         if (root == nullptr)
        return 0;

    // compute the height of left and right subtrees
    int lHeight = maxDepth(root->left);
    int rHeight = maxDepth(root->right);

    return max(lHeight, rHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        
       int firstHeight = maxDepth(root->left);
       int secondHeight = maxDepth(root->right);
    
    if(abs(firstHeight-secondHeight)>1) return false;

    return isBalanced(root->left) && isBalanced(root->right);
    }
};