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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        int ub=INT_MAX;
        return build(preorder,i,ub);
    }
    TreeNode* build(vector<int>& v, int &i, int ub)
    {
        if(i==v.size() || v[i]>ub) return NULL;
        TreeNode* root=new TreeNode(v[i++]);
        root->left=build(v,i,root->val);
        root->right=build(v,i,ub);
        return root;
    }
};