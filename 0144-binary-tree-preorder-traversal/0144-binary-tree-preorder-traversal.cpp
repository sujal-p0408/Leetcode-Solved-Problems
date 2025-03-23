class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode* cur = root;

        while (cur != NULL) {
            if (cur->left == NULL) {
                preorder.push_back(cur->val);
                cur = cur->right;
            } else {
                TreeNode* prev = cur->left;
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }

                if (prev->right == NULL) {
                    // Create thread
                    prev->right = cur;

                    // ✅ Add value before going left
                    preorder.push_back(cur->val);

                    cur = cur->left;
                } else {
                    // Thread already exists, remove it
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }

        return preorder;
    }
};
