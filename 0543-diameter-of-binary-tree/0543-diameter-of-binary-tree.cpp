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
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0; // Initialize the diameter
        cal(root, d); // Pass d by reference
        return d;
    }

    int cal(TreeNode* root, int& d) // Pass d by reference
    {
        if(root==nullptr) return 0;

        int lh=cal(root->left, d);
        int rh=cal(root->right, d);

        d=max(d,lh+rh);

        return 1+max(lh,rh);
    }
};