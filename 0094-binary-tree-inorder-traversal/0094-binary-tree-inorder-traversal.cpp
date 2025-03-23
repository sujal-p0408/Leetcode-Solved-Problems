class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* cur = root;

        while (cur != NULL) {
            if (cur->left == NULL) {
                // ✅ Process the current node
                inorder.push_back(cur->val);
                cur = cur->right;
            } else {
                TreeNode* prev = cur->left;

                // Find the rightmost node in left subtree or thread
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }

                if (prev->right == NULL) {
                    // Create thread to the current node
                    prev->right = cur;
                    cur = cur->left;
                } else {
                    // Thread exists, remove it and process current
                    prev->right = NULL;

                    // ✅ Process current after left is done
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }

        return inorder;
    }
};
