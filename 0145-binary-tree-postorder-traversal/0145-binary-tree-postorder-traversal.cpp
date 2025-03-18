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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>postorder;
        stack<TreeNode*> st1,st2;
        if (root == nullptr) return postorder;
        st1.push(root);
        // if(st1.empty()) return postorder;
        TreeNode* node;
        while(!st1.empty())
        {
           node=st1.top();
           st1.pop();
           postorder.push_back(node->val);
           if(node->left) st1.push(node->left);
           if(node->right) st1.push(node->right);
        }

        // while(!st2.empty())
        // {
        //     postorder.push_back(st2.top()->val);
        //     st2.pop();
        // }
        reverse(postorder.begin(),postorder.end());
        return postorder;
    }
};